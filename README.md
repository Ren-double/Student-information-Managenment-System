## Student Information Management System (Version 1)

### [Experimental Objectives]  

1. Apply C language programming techniques comprehensively to solve practical problems.
2. Design and implement a management system using the C language according to given requirements.

### [Experimental Contents]

1. Design and implement a management system for information categories (such as student management, staff management, attendance management, email management, express information management, etc., not limited to these). 
2. Functions should include at least adding information, deleting information, modifying information, and querying information.
3. You can design and implement other more functions according to your own ideas, such as sorting, data statistics, data analysis, data screening, data visualization, etc.
4. Use a menu to interact with users, and the program can perform corresponding operations according to the user's selection.
5. Be able to write information into a file for persistent storage and read information from the file.
6. Use functions to implement each functional module separately.
7. The program design, custom data types, and code structure should be reasonable.
8. The code must have complete annotation content, and the business logic must be implemented correctly.
9. The experimental report must include system function descriptions, program design explanations, source code, screenshots of running results, etc.

#### I. System Function Descriptions (Shown in three code files as follows)

##### 1. Initialization and Ending Stages

###### (1) Code written in main.c

(a) A function to determine whether it is the first time to enter the system as a principal or teacher: bool FIRST(char p[]); (The teacher's password will be stored in Secure_Teacher.txt, and the principal's password will be stored in Secure.txt)

(b) A function to log out of the system: void Destory();

(c) A function for selecting the identity to enter the system, which is an essential function for the entire system: int main();

###### (2) Code written in school.h

(a) Define the student structure: struct Student{};

(b) A function to define a student structure head node: struct Student* head_;
                                        static int geshu = 0;
                                        static void StudentInit();

It is defined as a static function because there is only one such functional function throughout the system's life cycle.

(c) A function to determine whether there is a file storing student information: static void File(int* ge);

It is defined as a static function because there is only one function to read whether there is a file at the start throughout the system's life cycle.

(d) A function to release the memory of the student linked list each time when exiting the student information management system: static void StudentEnd();

The student structure includes: student's name, age, gender, student number, math score, English score, Chinese score, and total score.

It is defined as a static function because there is only one such functional function throughout the system's life cycle.

(e) Define a principal structure: struct Headmaster{};

##### 2. Principal Module

###### (1) All functional functions of the principal module are written in school.h

(a) The principal's initialization function, where the principal inputs his/her authority key and determines whether he/she is the real principal: static void HeadmasterInit();

(b) A function to display the principal's administrative functions: void Administration();

(c) A function to determine which work the principal will do: void oper(int value, int* ge);

(d) A function for the principal to input basic student information: void hpush(int* ge);

(e) A function for the principal to delete student information: void hdelete(int* ge);

(f) A function for the principal to query student information: void hFind();

(g) Functions for the principal to change student information: void hChange(), bool Alter(char* c);

(h) A function for the principal to change the password: void ChangeSecure(char p[]);

(i) A function for the principal to display all student information: void hshow();

(j) A function for the principal to delete all student information: void DeleteAll(int *ge);

##### 3. Teacher Module

###### (1) All functional functions of the teacher module are written in school.h

(a) The teacher's initialization function, where the teacher inputs his/her authority key and determines whether he/she is the real teacher: static void TeacherInit();

(b) A function to display the teacher's administrative functions: void TeAd();

(c) A function to determine which work the teacher will do: void Toper(int val);

(d) A function for the teacher to input and change student grades: void Tpush(int val);

(e) The functions for the teacher to query student information, display all student information, and change the teacher's password are shared with the principal module.

(f) Functions for the teacher to rank student grades: struct Student* merge(struct Student* left, struct Student* right), struct Student* mergeSort(struct Student* head), void sortList();

Here, merge sort is used, which is more efficient. The specific functions of the three functions can be seen in the comments of the basic source code module.

(g) A function for the teacher to print the student grade ranking: void PrintGrade(struct Student* m);

##### 4. Student Module

###### (1) All functional functions of the student module are written in Student.h

(a) A function for the student to input the student number when entering the student module to determine whether the student exists in the system: static void Student_Oper();

(b) A function to display student functions: void StudentMemu();

(c) A function to determine which operation the student will perform: void Opertor(int val, char ch[]);

(d) A function for the student to find information: void FindInformation(char ch[]);

(e) A function to determine whether the student can change information, requiring the student to input the teacher's authority key: void bool_ChangeInformation(char hao[]);

(f) A function for the student to modify information: void Change_Information(char xuehao[]);

##### 5. Other Functional Modules

###### (1) All are written in Student.h

(a) A function to save student information in a file: void Save(struct Student* s, int ge);

(b) File processing when changing or deleting student information: void Changefile();

(c) A function to input the student grade ranking into the file: void PushGrade(struct Student* m);

(e) A function to perform simple decryption using the Caesar cipher: static void Secure(char p[], int n);

(f) A function to perform simple encryption using the Caesar cipher: static void Secure2(char p[], int n);

#### II. Program Design Explanation

This student information management system aims to provide a convenient platform for managing students' basic information, grades, and related operations, and is mainly divided into the following modules:

##### 1. Overall System Architecture

- The system adopts a modular design and is divided into initialization and ending stages, principal module, teacher module, student module, and other functional modules. Each module's functions are relatively independent, facilitating maintenance and expansion.
- Each functional module is implemented separately by functions, improving the code's readability and reusability.

##### 2. Data Structure Design

- The student structure `struct Student` is defined, which contains information such as the student's name, age, gender, student number, math score, English score, Chinese score, and total score, used to store students' detailed data.
- A linked list structure is used to manage student information, and the pointers `st` in the structure connect each student node, facilitating operations such as adding, deleting, modifying, and querying information.

##### 3. Functional Module Design

- **Initialization and Ending Stages**
  - The `FIRST` function is used to determine whether it is the first time to enter the system. If it is the first time, it prompts to set the principal's or teacher's password and stores it in an encrypted manner.
  - The `Destory` function implements the system logout function, which requires inputting the principal's authority key for verification, and deletes relevant system files upon success.
  - The `main` function serves as the program entry, responsible for initializing the student linked list, detecting files, displaying menus, and calling corresponding modules according to user selection.
- **Principal Module**
  - The `HeadmasterInit` function is used for principal initialization. The principal inputs the password and verifies it. If correct, he/she enters the principal's administrative function interface.
  - The `Administration` function displays the principal's administrative function menu, including operations such as inputting, deleting, changing, and querying information, displaying all student information, deleting all student information, changing the principal's password, and exiting the system.
  - The `oper` function calls corresponding functional functions according to the principal's selected operation number, such as `hpush` (inputting information), `hdelete` (deleting information), `hChange` (changing information), etc.
- **Teacher Module**
  - The `TeacherInit` function is used for teacher initialization. After verifying the password, the teacher enters the teacher's administrative function interface.
  - The `TeAd` function displays the teacher's administrative function menu, including operations such as inputting student grades, changing student grades, querying student information, displaying all student information, ranking student grades, changing the teacher's password, and exiting the system.
  - The `Toper` function calls corresponding functional functions according to the teacher's selected operation number, such as `Tpush` (inputting and changing student grades), `hFind` (querying student information), `hshow` (displaying all student information), `sortList` (ranking student grades), etc.
- **Student Module**
  - The `Student_Oper` function, when a student enters the system, determines whether the student exists based on the input student number. If it exists, the student enters the student function menu.
  - The `StudentMemu` function displays the student function menu, including operations such as viewing information, changing information, and exiting the system.
  - The `Opertor` function calls corresponding functional functions according to the student's selected operation number, such as `FindInformation` (finding information), `bool_ChangeInformation` (determining whether information can be changed), etc.
- **Other Functional Modules**
  - The `Save` function is used to save student information into a file to ensure persistent data storage.
  - The `Changefile` function performs corresponding processing on the file when changing or deleting student information to ensure file data consistency.
  - The `PushGrade` function inputs the student grade ranking information into the file to facilitate viewing the grade ranking situation.
  - The `Secure` and `Secure2` functions implement decryption and encryption functions of the Caesar cipher, respectively, used for secure storage and verification of passwords.

##### 4. File Operation Design

- The `File` function detects whether there is a file storing student information when the system starts. If it exists, it reads the file content and constructs the student linked list.
- After operations such as adding, deleting, and modifying information, the `Save`, `Changefile`, and `PushGrade` functions are called in time to update the file content, ensuring synchronization between the file and the data in memory.

##### 5. Password Management Design

- The Caesar cipher is used to perform simple encryption on the principal's and teacher's passwords to increase password security.
- When verifying the password, the input password is decrypted first and then compared with the password stored in the file to ensure password correctness.

##### 6. Interface Design

- Rich ASCII art patterns and color control codes are used to add interest and distinguishability to the menu interfaces of different modules, improving the user experience.
- During the operation of the system, clear prompt information is provided in a timely manner to guide users to perform correct operations, and friendly prompts are given for incorrect inputs.

#### III. Performance Analysis of Storing Student Information in Linked List

##### 1. Insertion Performance

- When inserting a new node at the head of the linked list, the time complexity is $O(1)$ because only the pointers of the new node and the head node need to be modified without traversing the linked list.
- When inserting a node in the middle or at the end of the linked list, the time complexity is $O(n)$, where $n$ is the length of the linked list. It is necessary to traverse the linked list to find the insertion position, and on average, about $n/2$ nodes need to be traversed.

##### 2. Deletion Performance

- When deleting the head node of the linked list, the time complexity is $O(1)$, and the head node pointer can be directly modified.
- When deleting a node in the middle or at the end of the linked list, the time complexity is $O(n)$. It is necessary to traverse the linked list to find the node to be deleted, and on average, about $n/2$ nodes need to be traversed.

##### 3. Search Performance

- When searching for student information by student number, the worst-case time complexity is $O(n)$, and the entire linked list needs to be traversed to find the target node or determine that the node does not exist.
- If the linked list is ordered, optimization strategies such as binary search can be adopted, but the implementation is relatively complex, and the system does not mention the orderliness of the linked list, so sequential search is used by default.

##### 4. Memory Management Performance

- The advantage of linked list storage is that it dynamically allocates memory, can flexibly adapt to changes in data volume, and does not need to pre-allocate a large amount of continuous memory space, avoiding memory waste.
- However, frequent dynamic memory allocation and release (such as insertion and deletion operations) may lead to memory fragmentation, affecting memory utilization and allocation efficiency. In large-scale data operations, memory fragmentation consolidation or other memory management strategies may need to be considered.

##### 5. Space Performance

- In addition to storing data itself, the linked list node requires additional pointer space to maintain the connection relationship between nodes. For each student node, the pointer occupies a certain amount of memory space, which increases memory overhead to a certain extent.
- Compared with continuous storage structures such as arrays, linked lists may save more space when storing sparse data or when the data volume is uncertain because there is no need to reserve a large amount of continuous space. But if the data volume can be determined in advance and is relatively stable, arrays may have advantages in space utilization.

##### 6. Traversal Performance

- When traversing the linked list to obtain all student information, the time complexity is $O(n)$, and each node needs to be visited in turn. The traversal process is relatively simple, but the performance is greatly affected by the length of the linked list.

##### 7. Data Update Performance

- When updating student information, the target node needs to be found first, and the time complexity is $O(n)$. After finding it, the time complexity of modifying the node data is $O(1)$. The overall time complexity of the update operation mainly depends on the search process.

##### 8. Stability Analysis

- The linked list structure is relatively stable in scenarios with frequent data insertion and deletion and will not cause a severe performance decline due to large amounts of data movement like arrays. However, if the linked list is too long and memory management is improper, problems such as insufficient memory or memory fragmentation may occur, affecting system stability.

##### 9. Comparison with Other Data Structures

- Compared with arrays, linked lists have advantages in insertion and deletion operations, especially when the data volume is uncertain or changes frequently. But arrays perform better in random access and memory continuity. For frequent search operations (if the index is known), arrays are more efficient.
- Compared with advanced data structures such as binary search trees, the search performance of linked lists is worse. In a balanced state, the average time complexity of search, insertion, and deletion operations of binary search trees is $O(log n)$, but the implementation and maintenance are relatively complex.

##### 10. Directions for Optimization

- If insertion and deletion operations are frequently performed and high search performance is required, balanced binary search trees or other more advanced data structures can be considered to replace the linked list.
- For frequent search operations, indexing can be considered or the linked list can be sorted to improve search efficiency, but the sorting operation itself also has certain time and space costs and needs to be weighed according to the actual situation.
- Optimize the memory management strategy, such as regular memory fragmentation consolidation or using memory pool technology to improve memory utilization and allocation efficiency.

In conclusion, storing student information in a linked list has advantages in the flexibility of insertion and deletion operations, but the search performance is relatively weak, and attention should be paid to memory management and space utilization.

#### IV. Basic Source Code

###### (1) main.c Code:

    It displays the basic menu, covering several basic functions of the student information management system. The user selects functions, and corresponding functions are called.
    It detects whether there is a file or not and performs corresponding operations.
    It determines whether it is the first time to enter the management system and performs corresponding operations.

###### (2) school.h Code

    It contains the structures of the school's principal, teachers, and students.
    It contains various functions of the principal.
    It contains various functions of the teachers.
    It contains file input and output functions.


###### (3) Student.h Code

    It contains three functions of students.
    It contains functions for the specific implementation of functions.
