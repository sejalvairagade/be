// SPDX-License-Identifier: MIT
pragma solidity ^0.8.17;

contract StudentData {

    // Structure to store student details
    struct Student {
        uint id;
        string name;
        uint age;
    }

    // Dynamic array of all students
    Student[] private students;

    // Mappings for quick lookups
    mapping(uint => Student) private studentById;      // ID → Student details
    mapping(string => uint[]) private idsByName;       // Name → List of IDs with same name

    // ➕ Add a new student
    function addStudent(uint _id, string memory _name, uint _age) public {
        require(studentById[_id].id == 0, "ID already exists"); // Prevent duplicate IDs

        Student memory newStudent = Student(_id, _name, _age);
        students.push(newStudent);
        studentById[_id] = newStudent;

        idsByName[_name].push(_id); // Keep track of all IDs for this name
    }

    // 📋 Get student by array index
    function getStudent(uint index) public view returns (uint, string memory, uint) {
        require(index < students.length, "Invalid index");
        Student memory s = students[index];
        return (s.id, s.name, s.age);
    }

    // 🔍 Get student by ID
    function getStudentById(uint _id) public view returns (uint, string memory, uint) {
        require(studentById[_id].id != 0, "Student not found");
        Student memory s = studentById[_id];
        return (s.id, s.name, s.age);
    }

    // 🧾 Get all student IDs by name
    function getStudentIdsByName(string memory _name) public view returns (uint[] memory) {
        return idsByName[_name];
    }

    // 🔁 Get all student details by name (if multiple have same name)
    function getStudentsByName(string memory _name) public view returns (Student[] memory) {
        uint[] memory ids = idsByName[_name];
        Student[] memory result = new Student[](ids.length);

        for (uint i = 0; i < ids.length; i++) {
            result[i] = studentById[ids[i]];
        }

        return result;
    }

    // 📊 Get total number of students
    function getCount() public view returns (uint) {
        return students.length;
    }

    // Accept ETH (optional)
    fallback() external payable {}
    receive() external payable {}
}
