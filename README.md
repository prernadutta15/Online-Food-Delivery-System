# Online-Food-Delivery-System

## SOFTWARE REQUIREMENT SPECIFICATION

## TABLE OF CONTENTS
ABSTRACT…………...……………………………………………………………5
ACKNOWLEDGEMENTS………………………………………………………..6
1. INTRODUCTION………....…………………………………………………….7
	1.1 PURPOSE……….……………………………………………………….7
	1.2 SCOPE……………………………………………………………………7
	1.3 DEFINITIONS, ACRONYMS AND ABBREVIATIONS…………..8-9
           1.4 OVERVIEW……………………………………………………………..9
2. OVERALL DESCRIPTION…………………………………………………...10
2.1 PRODUCT PERSPECTIVE……………………………………….......10
2.2 PRODUCT FUNCTIONS…………………………………………..10-11
2.3 USER CHARACTERISTICS………………………………………….11
2.4 GENERAL CONSTRAINTS…………….…………………………….12
	2.4.1 TECHNICAL CONSTRAINTS………………………………12
	2.4.2 FUNCTIONAL CONSTRAINTS……………………………..12
2.5 ASSUMPTIONS AND DEPENDENCIES…………………………….12 
3. SPECIFIC REQUIREMENTS...………………………………………….........13
	3.1 EXTERNAL INTERFACE REQUIREMENTS……………...……….13
		3.1.1 USER INTERFACES…………………………………………..13
		3.1.2 SOFTWARE INTERFACE…………………………………..…13
		3.1.3 HARDWARE INTERFACE………………………………….....13
		3.1.4 COMMUNICATION INTERFACE……………………………13
4 REQUIREMENTS…………………………………………………………………14
	4.1 FUNCTIONAL REQUIREMENTS……………………………………...14
	4.2 PERFORMANCE REQUIREMENTS...............................................…...14
	4.3 SECURITY REQUIREMENTS………………………………………….14
	4.4 QUALITY REQUIREMENTS…………………………………………...15
5 CONCLUDING REMARKS………...…………………………………………….15

## ABSTRACT
“Software engineering is not about right and wrong but only about better and worse”-Ellen Ullman.
If we dive deep into the timeline of software engineering, a severe software crunch gripped the market around 1980s. As hardware sophistication had outpaced the ability to develop software, there was a need to enhance software capabilities by making them robust and more maintainable. What started as an art form had now evolved into a concrete procedure requiring skill and technical agility. Also, incorporation of relatively intricate functionalities required an equipped multi-membered team that needed to coordinate and cooperate without causing inadvertent overwrites. Thus, there was an immediate need to define a software development process and to assign standards for development and documentation. Any software that cannot meet the demands of time gets obsolete. An immaculate SRS is the first step to a good software that can be maintained over time.
This document follows the standards of SRS documentation with a detailed understanding of system functionalities and provides a comprehensive and process-centric overview of the system as a whole as well as from various perspectives of the users and stakeholders involved. This document has been designed with the goal to act as a bridge between the client and the developers and may be referred to in case of any clarification and/or justification.
 ACKNOWLEDGEMENT
It is a genuine pleasure to express our deep sense of gratitude to our project guide and mentor Professor TV Vijay Kumar. His keen interest, support, enthusiasm and above all his overwhelming attitude to guide his students has been solely and mainly responsible for completing our work. His timely advice, meticulous scrutiny, valuable guidance and scientific approach has ushered and inspired us to a great extent to successfully accomplish this project.
		We are also indebted to him for imbibing in us a sense of responsibility and team spirit by assigning us teams and for encouraging us to work together towards a common goal. This project has given us a better insight about the subject and the implementation has given us a golden opportunity to apply what we have learnt in the class and we shall forever be grateful for the same.
		
## 1. INTRODUCTION
“We may hope that machines will eventually compete with men in all purely intellectual fields”-Alan Turing.
Initially what had started with designing calculators to help mathematicians, computers have superseded its initial goal to seep into every aspect of human life. To keep pace with the online world, this project aims to provide an interactive platform to its users for ordering food online instead of visiting restaurants.
This section aims to specify the purpose of the document along with the list of terminologies and abbreviations being used for the same.
### 1.1 PURPOSE
The purpose of this document is to comprehend, analyze and list out the requirements for the “Online Food Delivery” software. It also aims to illustrate the expected outcome of the system and to identify the limitations, constraints and technical restrictions involved by understanding the perspective of the various stakeholders and developers involved in the software development process. 
### 1.2 SCOPE
This project aims to widen its scope by making it as inclusive as possible – the user need not be proficient in technical aspects in order to use the software – just the ability to use a computer is sufficient. For this, the user interface needs to be as simple as possible with elaborate messages and user-friendly interaction.
The client using the software for searching restaurants should also have the ability to select a restaurant based on a number of parameters such as preferences, location, price, discounts available, etc.


## 1.3 DEFINITIONS, ACRONYMS AND ABBREVIATIONS
The abbreviations used in the document are as follows:

	SRS: Software Requirements Specification

	COD: Cash On Delivery

	CLI: Command Line Interface

	RAM: Read Only Memory

	OS: Operating System

	MB: Megabytes
The most commonly used technical terms are described as follows:

	SRS: This document itself is the SRS. It is to be signed as a contract between the client and the software company and should be referred to in case of any discrepancy/dispute.

	Interface: The interface is the platform using which the customer or client interacts with the software. Simply put, it is the part of the software that is visible to the user.

	Front-end: The part of the software responsible for interaction with the user. 

	Back-end: The part of the software that stores data entered by the user.

	Database: The systematic collection of data in an organized manner so that it is easy to store, edit and recover.

	Reliability: It is a quantitative parameter to judge the performance of a software. For example, a reliability of 90% means that the software should successfully execute 90 times out of 100.

	Read-Only View: A read-only view allows partial access to the customer. The customer can only view the data but cannot make any modifications in the database.

	Admin: The admin is the owner of the software. Once the software is complete, the software product is handed to the client, who now becomes the admin of the software. The admin is provided with a username and password using which he/she can access the databases and edit them. There can be more than 1 admin.

	Client: The client is a person who requests for a service. In this case, the person or person(s) or the organization who wants to get a food delivery system developed, is the client.

	Customer: The customer is a person or organization that uses the software. They are the target audience for whom the software has been developed. In this case, people who wish to use the software to book a food item for them are the customers.

## 1.4 OVERVIEW
The following section comprises two chapters, the first providing a detailed overview of the product to be developed, along with any constraints and user details, while the second chapter analyses the system with a process-centric view point by identifying the functionalities and any restrictions imposed by the hardware or software.

# 2. OVERALL DESCRIPTION
This portion presents an overview of the system with reference to what kind of users and stakeholders will interact with the system along with a brief introduction to the functionalities of the system. The various constraints and dependencies shall also be listed down in this section.
## 2.1 PRODUCT PERSPECTIVE
The owner or the admin maintains a list of restaurants affiliated to the organization using the interface. The user can create an account in the “Online Food Delivery System” and log in using his credentials.
The user now can view all the restaurants available or perform an advanced search based on the following criteria:

	Restaurant name

	Cuisine name

	Food item name

	Location

Once the user selects his/her desired item(s) from the menu, the order is placed to the restaurant that accepts or declines the order. If the order is declined, an appropriate message is displayed asking the user to try a different restaurant whereas if the order is accepted, the bill is generated that displays:

	Item(s) ordered

	Total bill to be paid

	Receipt number

The admin must be able to view all the restaurants and the complete customer details. 
## 2.2 PRODUCT FUNCTIONS
The functionalities of the users of the system are specified in the following page:

CUSTOMER FUNCTIONALITIES:

	Authenticate customers

	Show available restaurants

	Provide interface to select menu

	Provide confirmation

	Provide bill receipt

ADMIN FUNCTIONALITIES:

	View all restaurants

	View all customers

	View all purchases

	Store restaurant contact details

	Add new restaurants

	Add new admins

Due to certain limitations imposed on the software (as mentioned later) the admin is expected to manually contact the restaurant owner for order confirmation and it is the prerogative of the restaurant to prepare and deliver the order in time by sending its own valet (whose details shall be shared to the customer and the admin). 

## 2.3 USER CHARACTERISTICS
There are basically two categories of users identified- first, the naïve customers at the front-end who have little to no knowledge about the technical nitty-gritties involved in developing the software and second, the admin (our client) who are comparatively more comfortable with the software (maybe after few training sessions if required). The customer interface thus, demands greater precision and simplicity whereas the admin interface might require the admin to type in commands in order to perform intended tasks.

## 2.4 GENERAL CONSTRAINTS
Due to the implementation in C, several functionalities might be restricted. They are listed as follows:
TECHNICAL CONSTRAINTS

	Due to inability to use a sophisticated database, the software shall use basic file handling wherein the retrieval and the response time shall be high.

	Due to lack of GPS facilities, tracking a valet shall not be possible.

	There shall be no learning from past experiences and hence no restaurants can be suggested as per customer preferences.

	The users shall have to interact using the command prompt due to lack of an interface.

FUNCTIONAL CONSTRAINTS

	After the customer places his order, the admin shall have to manually contact the restaurant as there is no option to notify restaurants. Due this lack of automation, there is a slight chance of the restaurant not receiving the order, which shall lead to order cancellation and might increase customer dissatisfaction.

	Due to the lack of a secure payment gateway, the mode of payment will have to be COD, that is, cash on delivery.

2.5 ASSUMPTIONS AND DEPENDENCIES
The restaurant may reject the order if it has other pre-accepted orders and hence the timing of the order is a major dependency.
It is expected to achieve 95% reliability: this means that out of every 100 transactions, at least 95 of them must run to completion with appropriate output.
The valet may or may not be available to deliver the items. Even in that case, the order needs to be cancelled. Also, the restaurant and the rider should be contacted manually by the admin after each order is placed.

# 3.  SPECIFIC REQUIREMENTS
## 3.1 EXTERNAL INTERFACE REQUIREMENTS
### 3.1.1 USER INTERFACES
Front-end: Command prompt to communicate with customers.
The users shall communicate by responding to instructions by pressing number keys corresponding to the intended task. This interface shall made as interactive as possible.
Back-end: To store customer and restaurant details in files.
The name, location and contact details of the restaurant need to be stored along with the customer data. File handling shall be used to achieve this.

### 3.1.2 SOFTWARE INTERFACE
OPERATING SYSTEM: 

	Windows

	Linux

3.1.3 HARDWARE INTERFACE

	Command Prompt

	Standard Editor

	500MB RAM

### 3.1.4 COMMUNICATION INTERFACE
The communication or interaction between the admin and the customer takes place through the CLI, that is, command line interface. The database is to be accessed via any standard text viewing application such as Notepad++.

# 4. REQUIREMENTS
## 4.1 FUNCTIONAL REQUIREMENTS

	There should not be abrupt abortion of code: The software is expected to run smoothly and handle any anomalous or erroneous input. In case an incorrect input is entered, the software should redirect the user to the initial point after displaying an appropriate message, rather than coming to a halt. For example, if a user inadvertently enters an alphabet instead of digit in a phone number, the program should include a provision for re-entering the phone number rather than causing the software to crash.

	User should be able to search for items in more than one way:

	View all the restaurants providing services

	Search on the basis of a certain food item the user wishes to consume

	Search on the basis of a particular cuisine.

	The user can use the software only upon successful registration.

	The user name should be unique.

	The user details entered during registration must be valid data.

	In case, of invalid data, the user is denied access and is requested to register again.

## 4.2 PERFORMANCE REQUIREMENTS
The software needs at least 500 MB RAM and C compiler. Since C is a platform dependent language, execution on any other platform might require minor changes in the code. This software has been designed in the LINUX platform, however, keeping in mind the popularity and the ease of using WINDOWS, this code can be executed on WINDOWS as well using any standard compiler such as TurboC++ or DEV C++.
## 4.3 SECURITY REQUIREMENTS 
In order to impose security constraints, only registered users can use the software. This prevents intrusion from unauthorized people. The users cannot however, edit the restaurant details, they are allowed to access the database in a read-only mode.
## 4.4 QUALITY REQUIREMENTS

	Fault tolerance – The software should be robust enough to respond to unexpected situations or anomalies more than 50% of the time.

	Reliable – The software should meet all the functional requirements.

	Maintainable – The software should be easy to maintain over the period of time. This requires proper documentation. The standards of computer programming also needs to be followed.

	Modifiable – The software should be developed such that it is feasible to incorporate new requirements over the period of time.

	Adaptability – Though the software is designed keeping in mind the LINUX environment, it should be adaptable enough to be executed in other environments such as WINDOWS as well.

# 5. CONCLUDING REMARKS
These SRS Software Third Party Terms and Conditions set forth the terms and conditions applicable to certain third party functionality, software or data located within the SRS Software licensed to Customer. All software, documentation and media provided to Customer under this Agreement are also subject to the terms and conditions of the applicable SRS Software License Agreement relating to the Software. Terms not defined in these Third Party Terms are as defined in the License Agreement. These Third Party Terms and may be updated and modified from time to time by SRS to reflect terms and conditions resulting from SRS’s ongoing relationships and contractual obligations with Third Party Providers. The SRS shall act as the first point of contact for Customer for problems relating to the Third Party Provider software referenced below and shall coordinate the resolution of any such problems with the Third Party Providers, as applicable.
		


# DESIGN DOCUMENT
In order to identify the modules involved, there was a need to comprehend the entire project from a process-centric point of view; to understand how the data flows from one process to another, how the processes modify the data and what is the final output of the system. Thus, a data flow diagram has been drawn in order to give a clear picture of the system from a process-centric point of view:
Conventions used in the data flow diagrams(DFDs):

				A process, typically written in the verb-object form is used to transform	inputs to outputs.
				A flow, represented by an arrow, is used to describe the movement of data in a system.
				
A data store models a collection of data packets at rest.
DATA FLOW DIAGRAM:
 
 ![image](https://user-images.githubusercontent.com/63841770/86944173-fc2e3b00-c164-11ea-91c7-b11283988f0e.png)
Fig 2: LEVEL 0 DFD
 
 ![image](https://user-images.githubusercontent.com/63841770/86944194-018b8580-c165-11ea-9f13-18d33478b7fb.png)
Fig 3: Level 1 DFD
The various processes, flows and data stores depicted in the level 1 DFD can be understood by referring to the data dictionary.

# DATA DICTIONARY:
The following data dictionary aims to explain every type of process, flow and store as defined in the data flow diagram. This gives an in-depth English explanation of the data and the existing constraints and assumptions, if any.
NAME	TYPE	DESCRIPTION
Login	Flow	The user is asked to login using his credentials.
Validation Card	Process	User is asked to enter his phone number as the username. If the phone number is not registered, he is redirected to the registration page and is first made to register. If the phone number is already registered, the user is asked to enter the password. If the credentials match, he/she is said to have valid credentials, else the validation process is continued till correct data is received.
Registered Users	Store	This is a database that stores the details of the registered users for further login purposes.
Valid Credentials	Flow	This flow transports the valid credentials, that is, username and password.
Check User Type	Process	A valid user is of two types: the admin or the customer. This process identifies the type of user.
Admin details	Flow	This flow carries the admin credentials.
Customer details	Flow	This flow carries the valid customer credentials.
Update Restaurants	Process	This process can be accessed only by the admin. It provides the following functionalities:
1)	Add a restaurant: The admin can add details of a new restaurant including its name, location, contact details and menu.
2)	Delete a restaurant: The admin can delete the records of a restaurant from the database and terminate the relations with the restaurant.
3)	View Customer Orders: The admin can see a list of orders placed by the customers as the copy of the bill is saved in the database.
4)	View Customer Details: The admin can view the details of the customers.
5)	Add new Admin: The admin can add new admins to the system.
View Restaurants	Process	The customer is allowed to access the database in a read-only mode. However, the customer can view the restaurants by applying several filters- the customer can search for suitable restaurants by an item name, by a cuisine style or by simply view the restaurant names.
Display Items	Process	If the admin wishes to view the restaurants he can enter the customer mode and proceed.
Restaurant Info	Store	This database stores the data pertaining to the restaurant including the name, location, contact details and menu. It is accessed in the write mode by the admin and is accessed in the read-only mode by the customer.
Update Request	Flow	Takes the update request from the admin to check for constraints.
Display Details	Flow	Before displaying details, this flow carries it to check if the constraints are maintained.
Check Constraints	Process	The various anomalous conditions handled by the process are:
a)	Admin side: 
1)	The admin did not make any update, so no action is performed
2)	The admin has entered some invalid data for example, a negative number as the price.
3)	The admin is trying to delete an entry which does not exist.
4)	The database is full and is unable to add new restaurants.
b)	Customer side:
1)	The customer tries to view a restaurant that is not affiliated to the software.
2)	The customer searches for a food item that is not offered by any of the restaurants.
3)	The customer searches for a cuisine that is not offered by any of the restaurants.
If the data entered into the database is found to be invalid, the last entry is automatically deleted.
Valid Values	Flow	Transports the valid values entered by the user after handling any anomalous state.
Add to Cart	Process	Keeps accepting orders till the user wants. A single user can order multiple items from the same restaurant but needs to re-login before placing order from another restaurant. This is for the sake of simplicity.
Cart Not Empty	Flow	Transports the message of whether the cart is empty or not empty.
Place Order	Process	If the cart is not empty, the user is asked for a confirmation message – if the user confirms, the bill is generated (displaying the timestamp, user name, address, restaurant name and order details and total amount payable). If the cart is empty, the order is automatically cancelled and is directed towards the rejection card.
Customer Order	Store	This database stores every order placed by a customer and can be viewed only by the admin.
Valid Order	Flow	In case the order is valid, the bill is stored in the customer order database and this flow transports the message to the acceptance card. 
Invalid Order	Flow	If the order is invalid, this flow transports the message to the rejection card. The order is said to be invalid, if the cart is empty, the cart contains some invalid data such as a negative or a fractional quantity or a negative price. This flow also handles the case where the admin does not place any order and hence the cart is empty.
Rejection Card	Process	If the order is invalid, the order is rejected and the user is asked to re-login
Acceptance Card	Process	If the order is valid, the bill generated (displaying the timestamp, user name, address, restaurant name and order details and total amount payable) is stored in the customer order database and the user is given a confirmation message.
		
	Table 1: Data dictionary for processes, stores and flows in the level 1 DFD

# PROCESS SPECIFICATION:
## PRE-POST CONDITIONS:
The pre-conditions describe what holds true for processes to initiate whereas the post-conditions describe what holds true for processes to terminate. It describes how input is transformed to output without taking the algorithm into consideration.
PRE-CONDITION 1: Identify user type as ADMIN or CUSTOMER.
POST-CONDITION 1: Provide login/registration facilities.
PRE-CONDITION 2: User Type is ADMIN AND username and password matches.
POST-CONDITION 2: Allow the ADMIN to perform the following functionalities:
a)	Add a restaurant
b)	Delete a restaurant
c)	View Customer Orders
d)	View Customer Details
e)	Add new Admin
PRE-CONDITION 3: User type is ADMIN AND username and password does not match.
POST-CONDITION 3: Ask the ADMIN to try again OR login as a customer.
PRE-CONDITION 4: User type is CUSTOMER AND username and password matches.
POST-CONDITION 4: Allow the CUSTOMER to view restaurants, search by cuisine or item and then place an order.
PRE-CONDITION 5: User type is CUSTOMER AND username and password does not match.
POST-CONDITION 5: Asks the CUSTOMER to re-enter credentials OR to register as a new user.

## STRUCTURED ENGLISH:
IF USER TYPE is CUSTOMER 
THEN 
	IF username AND password matches
	THEN
		DO CASE:
		CASE variable=SEARCH_BY_NAME
			Display list of restaurants and their locations.
		CASE variable=SEARCH_BY_ITEM_NAME
			Display list of restaurants serving the searched item.
		CASE variable=SEARCH_BY_CUISINE
			Display list of restaurants offering the searched cuisine.
		OTHERWISE
			Display all restaurants.
		Place Order and confirm.
	ELSE
		Message to retry or to register as new user.
	ENDIF
ELSE IF TYPE IS ADMIN
THEN
	IF username AND password matches
	THEN
		DO CASE:
		CASE variable=ADD_RESTAURANT
			Add new Restaurant details to database
		CASE variable=DELETE_RESTAURANT
			Remove Restaurant details from the database
CASE variable=VIEW_ORDERS
	View all orders placed by the customers.
CASE variable=VIEW_CUSTOMERS
	View all the customer details.
CASE variable=ADD_ADMIN
	Add a new admin.
OTHERWISE
	Enter a valid option.
	ELSE 
		Message to login as CUSTOMER.
ENDIF
ENDIF

# SYSTEM DESIGN:
The main modules identified by the system are:
1)	VALIDATION: This module ensures that the user is authenticated to perform further actions. 
2)	CUSTOMER VIEW: If the user type is CUSTOMER and validation is performed, the customer is allowed to view the restaurants or to search for suitable restaurants based on the food items or the cuisines they wish to eat.
3)	PLACE ORDER: This module calculates the amount payable on the basis of price and quantity of ordered items and then generates a bill. This bill is then, presented to the user and is asked for confirmation, in case of an affirmative response, the order is finalized and a copy of the bill generated is stored as a record in the database.
4)	ADMIN FUNCTIONS: This module performs updating operations such as adding a restaurant, removing a restaurant, viewing customer details and adding new admins. Since a customer is a subset of the admin, the admin can perform all functionalities of the customer including placing an order.
## LOGICAL DESIGN:
The following section expands the previous section by describing the modules from an implementation point of view. It describes the functions that are required to be implemented in order to achieve the design as mentioned in the system design phase.


Function Name	Input	Output	Purpose
Validation
(A & C)	Type of User (admin/customer)	1 if user if valid, 0 otherwise	Provides necessary authentication by comparing the values entered by the user with those stored in the database.
Registration
(C ONLY)	Write access to register database	Details stored in the database.	Accepts details like name, address, phone number (username), and password and stores the details into the database for login.
IsUserUnique*
(A & C)	Username	1 if user is unique, 0 otherwise.	Checks if the phone number (username) entered by the user for registration has not been registered with previously. One phone number cannot be accountable for two user accounts.
AddRestaurant
(A ONLY)	Index	Details stored in restaurant database.	Accepts the new and unique index and corresponding to it, stores the restaurant details - location and name.
AddMenu
(A ONLY)	Index	Details stored in menu database.	Accepts the index and corresponding to it, stores the menu details – restaurant code, item code, item name, item price.
AddCuisine
(A ONLY)	Index	Details stored in cuisine database.	Accepts the index and corresponding to it, stores the cuisine details – restaurant code, cuisine code and cuisine name.
getIndex
(A ONLY)	Read and write access to index database	New index	Accesses the index database to retrieve the value of the index of the last restaurant added. It adds 1 to that index and returns the new index.
AddNewAdmin
(A ONLY)	Write access to admin database	New admin added to database	Adds new admin details to the database.
ViewCustomer
(A ONLY)	Read access to customer database	Display customer details	Prints the customer details and order history by reading from the customer database to the console.
View Restaurant
(A & C)	Read access to restaurant database	Display restaurant details	Displays the list of restaurants registered with the user.
SearchByItem
(C ONLY)	Read access to restaurant menu database	Display restaurants serving the item	Displays the list of restaurants serving the searched item.
SearchByCuisine
(C ONLY)	Read access to restaurant cuisine database	Display restaurants offering the cuisine	Displays the list of restaurants offering the mentioned cuisine.
acceptOrder
(C ONLY)	User name, hotel index	Store order in database	Accepts order from customer in the form of item code and quantity.
generateBill
(C ONLY)	Order stored in database	Displays bill	Displays the bill generated after order confirmation
validOrder*
(C ONLY)	Bill generated	1 if order is valid, 0 otherwise	Checks if order is valid in the following ways:
1)	Item code is valid
2)	Quantity is positive and a whole number <10
3)	Price is positive
4)	Hotel code is valid
Tokenize*
(A & C)	String to be tokenized, character on the basis of which string is to be tokenized.	Tokenized string	Breaks the string into tokens on the basis of the entered character such as blank space or ‘!’. The tokenized words can now be categorized such as username, password, etc and can be compared.
Formatting*
(A & C)	File name 	Formatted file	Opens the required file and formats it by eliminating consecutive blank spaces, removing empty lines, inserting special characters, and so on. This helps the file to be retrieved in the expected format.
			Table 2: Modules of the logical design
* Fields marked with a ‘*’ are not essential functions – however, they greatly contribute to the robustness and quality of the system and help in checking for constraints or to provide a proper formatting to the system.
A ONLY – The function performs actions related to Admin only.
C ONLY – The function performs actions related to the Customer only.
A & C – The function performs actions related to both Admin and Customer.
TYPES OF COHESION AND COUPLING TO BE ACHIEVED:
	DATA COUPLING: The aim is to enforce data coupling where no extraneous data is to be passed as a parameter, the arguments should be homogenous and every function should have only one entry point and only one exit point.
	FUNCTIONAL COHESION: The aim is to ensure functional cohesion where every module is responsible for performing a specific task. Every module takes an individual action and calls another function if it requires to perform any other task. 
This level of high cohesion and low coupling ensures modularity and a strong degree of interconnection between the modules while ensuring that the data of one module does not inadvertently affect the data of another module. Thus, no global variables or structures are to be declared or used.
CREATION OF STRUCTURE CHARTS:
 
 ![image](https://user-images.githubusercontent.com/63841770/86944211-094b2a00-c165-11ea-9fe3-acd51d566607.png)
				Fig 4: Simplified DFD
The terminologies and meaning of the DFD in figure 4 have been mentioned in the following table:
PROCESS	PROCESS NAME
P1	VALIDATION CARD
P2	CHECK USER TYPE
P3	VIEW RESTAURANT
P4	UPDATE RESTAURANT
P5	CHECK CONSTRAINTS
P51	ADMIN CONSTRAINT CHECK
P52	USER CONSTRAINT CHECK
P6	ADD TO CART
P7	PLACE ORDER
P8	ACCEPTANCE CARD
P9	REJECTION CARD
DATA FLOW 	DATA FLOW NAME 
D1	LOGIN INFO
D2	VALID CREDENTIALS
D3	CUSTOMER LOGIN INFO
D4	ADMIN LOGIN INFO
D5	INPUT FOR DISPLAY ITEM
D6	INPUT FOR DISPLAY DETAILS
D7	INPUT FOR UPDATION REQUEST
D8	VALID VALUES
D9	CART NOT EMPTY
D10	VALID ORDER DETAILS
D11	INVALID ORDER DETAILS
D12	ORDER REJECTED
D13	ORDER PLACED

## ALGORITHM:
### FOR CUSTOMER:
1)	Creates a new account and registers himself/herself.
2)	Enters username (phone number) and password to log in.
3)	If login is successful, go to 4, else go to 1.
4)	Press 1 to display restaurants, 2 to search by food item name, 3 to search by cuisine.
5)	The user needs to enter the hotel code.
6)	The restaurant associated the hotel code is displayed and its menu is print to the console.
7)	Enter item code and quantity
8)	Press 1 to continue
9)	If user enters 1 go to 7 else go to 10.
10)	Ask for confirmation, if user confirms, print bill else go to 4.
### FOR ADMIN:
1)	Login using credentials. If login fails, try to login as customer.
2)	Press 1 to add restaurants, 2 to delete restaurants, 3 to view customer orders, 4 to view customer details, 5 to add new admin.
3)	Call relevant functionality and ask if admin wants to place order.
4)	If admin wants to place order, perform customer functions from 4 to 10.

