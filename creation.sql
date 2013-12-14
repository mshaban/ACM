CREATE DATABASE SocialNetwork;

CREATE TABLE Users(
	id INT AUTO_INCREMENT,
	email VARCHAR(250) NOT NULL,
	passowrd VARCHAR(250) NOT NULL,
	first_name VARCHAR(250) NOT NULL,
	last_name VARCHAR(250) NOT NULL, 
	CONSTRAINT user_pk PRIMARY KEY (id)
);

CREATE TABLE Children(
	id INT,
	date_of_birth DATE NOT NULL,
	age INT NOT NULL, -- derived value
	FOREIGN KEY (id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT children_pk PRIMARY KEY (id)
);

CREATE TABLE Child_has_Interests(
	id INT,
	interest VARCHAR(250),
	CONSTRAINT child_has_interests_pk PRIMARY KEY (id,interest),
	FOREIGN KEY (id) REFERENCES Children(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Child_has_Hobbies(
	id INT,
	hobby VARCHAR(250),
	CONSTRAINT child_has_hobbies_pk PRIMARY KEY (id,hobby),
	FOREIGN KEY (id) REFERENCES Children(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Young(
	id INT,
	CONSTRAINT young_pk PRIMARY KEY (id), 
	FOREIGN KEY(id) REFERENCES Children(id) ON UPDATE CASCADE ON DELETE CASCADE
	-- 	CONSTRAINT  isYoung CHECK EXISTS (select u.age FROM Users u WHERE u.id = id AND u.age < 12 AND u.age > 7)
);

CREATE TABLE Parents (
	id INT,
	job VARCHAR(250),
	address VARCHAR(250),
	CONSTRAINT parents_pk PRIMARY KEY (id),
	FOREIGN KEY (id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Parents_has_Phones (
	id INT,
	phone VARCHAR(20),
	CONSTRAINT parentes_has_phones_pk PRIMARY KEY (id, phone),
	FOREIGN KEY (id) REFERENCES Parents(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE School_Principles(
	id INT,
	cpid INT UNIQUE,
	CONSTRAINT school_principles_pk PRIMARY KEY (id),
	FOREIGN KEY (cpid) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Schools(
	id INT AUTO_INCREMENT,
	name VARCHAR(250) NOT NULL,
	address VARCHAR (250) NOT NULL,
	educational_system VARCHAR (250) NOT NULL,
	sp_id INT,
	CONSTRAINT school_pk PRIMARY KEY (id),
	FOREIGN KEY (sp_id) REFERENCES School_Principles(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Advertisors(
	id INT,
	location VARCHAR(250) NOT NULL,
	field VARCHAR(250) NOT NULL,
	CONSTRAINT Advertisors_pk PRIMARY KEY User(id),
	FOREIGN KEY (id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Advertisors_phones(
	id INT,
	phone VARCHAR (20),
	CONSTRAINT advertisors_phones_pk PRIMARY KEY (id, phone),
	FOREIGN KEY (id) REFERENCES Advertisors(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Advertisments (
	a_num INT AUTO_INCREMENT, -- NOTE HERE
	aid INT,
	CONSTRAINT advertisment_pk PRIMARY KEY (a_num, aid),
	FOREIGN KEY (aid) REFERENCES Advertisors(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Advertisors_has_constract_Schools(
	sid INT,
	aid INT,
	CONSTRAINT contract_pk PRIMARY KEY (sid, aid),
	FOREIGN KEY (aid) REFERENCES Advertisors(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (sid) REFERENCES Schools(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Advertisors_shows_advertisments(
	aid INT,
	a_num INT,
	sid INT,
	uid INT,
	CONSTRAINT advertisors_shows_advertisments_pk PRIMARY KEY (aid, a_num, sid, uid),
	FOREIGN KEY (a_num,aid) REFERENCES Advertisments(a_num, aid) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (sid) REFERENCES Schools(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (uid) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
	-- check if the user is either children or parent
);

CREATE TABLE Experts (
	id INT,
	CONSTRAINT experts_pk PRIMARY KEY (id),
	FOREIGN KEY (id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Expert_Fields(
	id INT,
	field VARCHAR(250),
	CONSTRAINT Expert_Fields_pk PRIMARY KEY (id,field),
	FOREIGN KEY (id) REFERENCES Experts(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE School_principle_invites_experts(
	sp_id INT,
	s_id INT,
	exp_id INT,
	CONSTRAINT School_principle_invites_experts_pk PRIMARY KEY (sp_id, exp_id),
	FOREIGN KEY (s_id) REFERENCES Schools(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN  KEY (exp_id) REFERENCES Experts(id) ON UPDATE CASCADE ON DELETE CASCADE
	-- FUNCTION TO MAKE SURE THAT THE SCHOOL PRINCIPLE INVITES ONLY TO HIS SCHOOL
);

CREATE TABLE Club_admins(
	id INT,
	cp_id INT UNIQUE NOT NULL,
	CONSTRAINT Club_admins_pk PRIMARY KEY (id),
	FOREIGN KEY (cp_id) REFERENCES Contact_People(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Students_sign_up_school(	
	id INT,
	sid INT,
	sp_id INT,
	verify BOOLEAN,
	CONSTRAINT Students_sign_up_school_pk PRIMARY KEY (id, sid, sp_id),
	FOREIGN KEY (id) REFERENCES Children(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (sid) REFERENCES Schools(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (sp_id) REFERENCES School_principles(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Friend_Request(
	u1_id INT,
	u2_id INT,
	accept BOOLEAN,
	CONSTRAINT Friend_Request_pk PRIMARY KEY (u1_id, u2_id),
	FOREIGN KEY (u1_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (u2_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT Not_Eq CHECK (u1_id <> u2_id)
);

CREATE TABLE Games(
	id INT AUTO_INCREMENT,
	age_group INT,
	CONSTRAINT Games_pk PRIMARY KEY (id)
);

CREATE TABLE Users_Play_Games(
	g_id INT,
	u_id INT,
	CONSTRAINT Users_Play_Games_pk PRIMARY KEY (g_id, u_id),
	FOREIGN KEY (g_id) REFERENCES Games(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
	-- check if the user age is in the age group
);

CREATE TABLE Discussion_Boards(
	id INT AUTO_INCREMENT,
	CONSTRAINT Disscussion_Boards PRIMARY KEY (id)
);


CREATE TABLE Educational_Discussion_Boards(
	id INT,
	CONSTRAINT Educational_Discussion_Boards_pk PRIMARY KEY (id),
	FOREIGN KEY (id) REFERENCES Discussion_Boards(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Social_Discussion_Boards(
	id INT,
	CONSTRAINT Social_Discussion_Boards_pk PRIMARY KEY (id),
	FOREIGN KEY (id) REFERENCES Discussion_Boards(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Topics(
	t_num INT AUTO_INCREMENT, -- NOTE HERE
	s_id INT,
	topic VARCHAR (250),
	CONSTRAINT Topics_pk PRIMARY KEY (t_num, s_id),
	FOREIGN KEY (s_id) REFERENCES Social_Discussion_Boards(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE User_interacts(
	p_num INT AUTO_INCREMENT, -- NOTE HERE
	post VARCHAR(250),
	u_id INT,
	t_num INT,
	b_id INT,
	CONSTRAINT user_interacts_pk PRIMARY KEY (p_num,u_id,b_id,t_num),
	FOREIGN KEY (u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (t_num, b_id) REFERENCES Topics (t_num, s_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Questions (
	num INT AUTO_INCREMENT, -- NOTE HERE
	u_id INT,
	b_id INT, 
	question VARCHAR(250),
	CONSTRAINT Questions_pk PRIMARY KEY (num, u_id, b_id),
	FOREIGN KEY (u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (b_id) REFERENCES Educational_Discussion_Boards (id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Answers (
	a_num INT AUTO_INCREMENT, -- NOTE HERE
	q_num INT,
	exp_id INT,
	u_id INT,
	b_id INT,
	answer VARCHAR(250),
	CONSTRAINT answers_pk PRIMARY KEY (a_num, q_num, exp_id, u_id, b_id),
	FOREIGN KEY (q_num, u_id, b_id) REFERENCES Questions(num, u_id, b_id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (exp_id) REFERENCES Experts(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Posts_Photos(
	p_num INT AUTO_INCREMENT, -- NOTE HERE
	u_id INT,
	description VARCHAR(250),
	upload_date datetime,
	CONSTRAINT pp_pk PRIMARY KEY (p_num,u_id),
	FOREIGN KEY (u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Photo_Tags(
	p_num INT,
	u_id1 INT,
	u_id2 INT,
	CONSTRAINT photo_tags_pk PRIMARY KEY (p_num,u_id1,u_id2),
	FOREIGN KEY (u_id1) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (u_id2) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (p_num) REFERENCES Posts_Photos (p_num) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Photo(
	p_num INT,
	u_id INT,
	CONSTRAINT photo_pk PRIMARY KEY (p_num,u_id),
	FOREIGN KEY (p_num,u_id) REFERENCES Posts_Photos (p_num,u_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Posts(
	p_num INT,
	u_id INT,
	CONSTRAINT posts_pk PRIMARY KEY (p_num,u_id),
	FOREIGN KEY (p_num,u_id) REFERENCES Posts_Photos (p_num,u_id)

);
CREATE TABLE User_Comments (
	c_num INT AUTO_INCREMENT, -- NOTE HERE
	u_id1 INT,
	u_id2 INT,
	p_num INT,
	comment_text VARCHAR(250),
	CONSTRAINT comment_pk PRIMARY KEY (c_num,u_id1,u_id2,p_num),
	FOREIGN KEY (u_id1) REFERENCES Users (id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (p_num,u_id2) REFERENCES Posts_Photos (p_num,u_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Users_Tag_Users(
	u_id1 INT,
	u_id2 INT,
	u_id3 INT,
	p_number INT,
	CONSTRAINT tag_pk PRIMARY KEY(u_id1, u_id2, u_id3, p_number),
	FOREIGN KEY(u_id1) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE ,
	FOREIGN KEY(u_id2) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE ,
	FOREIGN KEY(p_number, u_id3) REFERENCES Posts_Photos(p_num, u_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Children_Updated_By_Parents(
	pid INT,
	cid INT,
	approve BOOLEAN,
	CONSTRAINT Children_Updated_By_Parents_pk PRIMARY KEY(pid, cid),
	FOREIGN KEY(pid) REFERENCES Parents(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(cid) REFERENCES Children(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Events(
	u_id int,
	event_number int AUTO_INCREMENT, -- NOTE HERE
	purpose varchar(250),
	description varchar(250),
	name varchar(250) NOT NULL,
	date_event datetime NOT NULL,
	location varchar(250),
	transport varchar(250),
	type_event varchar(250) NOT NULL,
	CONSTRAINT Events_pk PRIMARY KEY(event_number,u_id),
	FOREIGN KEY(u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE User_Invites_User(
	u_id2 int, -- Someone doesn't get invited more than once
	u_id1 int,
	u_id3 int,
	event int,
	accept boolean,
	CONSTRAINT User_Invites_User_pk PRIMARY KEY(u_id2, u_id3, event),
	FOREIGN KEY(u_id3, event) REFERENCES Events(u_id, event_number) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(u_id1) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(u_id2) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT diff CHECK (u_id1 <> u_id2)
);

CREATE TABLE Routes(
	p_id int,
	route_number int AUTO_INCREMENT, -- NOTE HERE
	max_number int,
	start_point varchar(250),
	end_point varchar(250),
	frequency int,
	CONSTRAINT Routes_pk PRIMARY KEY(route_number,p_id),
	FOREIGN KEY(p_id) REFERENCES Parents(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Routes_Stops(
	p_id int,
	route_number int,
	stop varchar(250),
	CONSTRAINT Routes_Stops_pk PRIMARY KEY(p_id, route_number, stop),
	FOREIGN KEY(p_id, route_number) REFERENCES Routes(p_id, route_number) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Parent_Invites_User(
	p_id int,
	u_id int,
	route_number int,
	CONSTRAINT Parent_Invites_User_pk PRIMARY KEY(p_id, u_id, route_number),
	FOREIGN KEY(p_id, route_number) REFERENCES Routes(p_id, route_number) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Clubs(
	id INT AUTO_INCREMENT,
	fee DECIMAL NOT NULL,
	location varchar(250) NOT NULL,
	open_hours TIME,
	close_hours TIME,
	CONSTRAINT Clubs_pk PRIMARY KEY(id)
);

CREATE TABLE Clubs_Activities(
	c_id int,
	activity varchar(250),
	CONSTRAINT Clubs_Activities_pk PRIMARY KEY(c_id, activity),
	FOREIGN KEY (c_id) REFERENCES Clubs(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Club_Joined_By_User(
	c_id int,
	u_id int,
	CONSTRAINT Club_Joined_By_User_pk PRIMARY KEY(c_id, u_id),
	FOREIGN KEY(c_id) REFERENCES Clubs(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(u_id) REFERENCES Users(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Sports(
	id int AUTO_INCREMENT,
	name varchar(250) NOT NULL,
	type_sport varchar(250),
	CONSTRAINT Sports_pk PRIMARY KEY(id)
);

CREATE TABLE Clubs_Has_Sports(
	cid int,
	sid int,
	CONSTRAINT Clubs_Has_Sports_pk PRIMARY KEY(cid, sid),
	FOREIGN KEY(cid) REFERENCES Clubs(id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(sid) REFERENCES Sports(id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Contact_People(
	id int AUTO_INCREMENT,
	sid int,
	CONSTRAINT Contact_People_pk PRIMARY KEY(id),
	FOREIGN KEY(sid) REFERENCES Sports(id) ON UPDATE CASCADE ON DELETE CASCADE
);


