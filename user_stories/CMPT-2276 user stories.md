### **User Stories Persona 1:**

1. As a Chair, I want all Faculty’s time and class preferences organized in one place to avoid managing countless emails and notes.  
   Acceptance Criteria:  
* Centralized inbox system should exist.  
* The Faculty’s preferences should be stored in a document and be retrievable by the Chair.  
* When Faculty members change their requests before the scheduling is in progress, the previously stored requests should be overridden.


2. As a Chair, I want to see potential class conflicts, so that I can avoid creating conflicting schedules.

Acceptance Criteria:

* Given that a room has been scheduled for a specific time, when the Chair tries to schedule another event in that room at the same time, the Chair should be notified or warned about the time conflict.   
* Given that a faculty member is assigned to a class at a specific time, when the Chair tries to schedule that faculty member to another class at the same time, the Chair should be notified or warned about the time conflict.   
* The chair should be able to view a list of all detected conflicts before finalising the schedule.  
    
3. As a Chair, I want the system to automatically distribute the workload among Regular and Temporary Faculty, so that scheduling is efficient and consistent.  
   Acceptance Criteria:  
* Given that there are multiple roles in the system and there is a “workload distribution weight factor”, when the Chair changes the weight factor for that role, the system should automatically assign members of that role a minimum number of classes in relation to the weight factor at the time of schedule creation.   
* Given that there is a menu listing all faculty members, when the Chair clicks on that member, the following menu should include information about whether that member has unassigned hours or is exceeding workload limits (that can occur due to manual editing by the Chair).  
    
4. As a Chair, I want to easily reschedule meetings so I can accommodate unforeseen changes.  
   Acceptance Criteria:  
* Given that a meeting time is set for other members, when the Chair changes that meeting time or location, it should be updated for all the others as well.  
* Given that I want to change the meeting schedule, when the Chair selects another time slot, it should show me if there is conflict or if the room is in use.   
* Given that when the Chair selects a meeting from a list of upcoming meetings, when they click “reschedule”, they should be shown a mini calendar with available time slots. 

### **User Stories Persona 2:**

1. As a Regular Faculty, I want to request preferred teaching slots, so that I can teach classes that align with my expertise and personal life.   
   Acceptance criteria   
* There should be a schedule draft where faculty members can select their preferred teaching time.  
* The system should allow Faculty members to rank their preference (first choice, second choice).  
* The system should validate that the requested slots do not overlap with existing faculty commitment.


2. As a Regular Faculty, I want to see more flexible teaching time, so that I can better balance my personal and professional life.  
   Acceptance Criteria:  
* The system should distribute most of the day classes (80%) between Regular Faculty   
* The schedule should fit the Faculty requests at least by 80%

3. As a Regular Faculty, I want to see course information beforehand, so that I can better prepare teaching materials.  
   Acceptance Criteria:  
* Faculty members should have access to course information as soon as the schedule is finalised.  
* Given that the Regular Faculty member is shown a list of classes they will be teaching, when they select a class, they should be shown the information and learning goal for that class. 

4. As a Regular Faculty, I want to see which courses I will teach in advance, so that I can prepare properly and be less stressed. 

Acceptance Criteria:

* Given that the class schedule has been created and the user is a Regular Faculty member, when the user logs in, they should be notified right away of all classes that they will teach.  
* Given that the user is shown a list of classes they will be teaching, when they select a class, the user should be shown the weekly schedule for that class. 

### 

### 

### 

### **User Stories Persona 3:**

1. As a temporary faculty, I want to take evening courses, so that my teaching does not interfere with my primary work.  
   Acceptance Criteria:  
* Given that the user is a Temporary Faculty and they are provided an interface to input their time preferences for each day, when they input the necessary information, the Chair should be able to see their teaching preferences.   
* Given that the Chair is trying to assign a class or courses to an instructor, when the chair chooses from a list of available instructors, the list of available instructors should be sorted in accordance to their preferences. 


2. As a Temporary Faculty, I want to receive timely notifications about schedule and class changes so that I can quickly respond to it. 	  
   Acceptance Criteria:  
* Given that the user is a Temporary Faculty, when the Chair reassigns them to a different class, then the system should display a notification and display it on the main menu page when the user logs in.   
* Given that the user is a Temporary Faculty and has been invited to a meeting, when the Chair changes the meeting schedule, should display a notification and display it on the main menu page when the user logs in. 


3. As a Temporary Faculty, I want to be able to request schedule adjustments so that I can manage conflicts with other commitments.  
   Acceptance Criteria:  
* Given that the user is given a list of classes that they will be teaching with the necessary schedule information, when they click on a class, the system should present a list of other sections for the same class.   
* Given that the user chooses another section of the same class, when they submit their request, the system should notify the Chair when they log in.  
* Given that the Chair is provided an interface to accept or reject the request of instructor change, when they accept, the system should switch the instructor of the two sections.


4. As a Temporary Faculty, I want a simple user interface so that I can quickly access the information and services that I need.   
   Acceptance Criteria:  
* The system should show a homepage with a menu given that the user is logged in.  
* Every menu option should be descriptive and have a clear functionality  
* Every button should have a clear icon and distinctive colors.


5. As a Temporary Faculty, I want all my work tools to be interconnected, so I can spend less time on organizational work and more on teaching.  
   Acceptance Criteria:  
* Given that a class has been canceled for some unforeseen reason and say there is a quiz on that day, when the instructor removes the quiz, it should be updated across the network and be reflected on the students course schedule as well.   
* Given that members in the college network have services such as Outlook or Google Calendar, when the instructor invites them to a meeting in the scheduling software, it should show up or notify them in their Outlook or Google Calendar. 