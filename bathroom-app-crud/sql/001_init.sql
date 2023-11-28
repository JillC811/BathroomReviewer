-- -----------------------
-- Users Table
-- -----------------------
CREATE TABLE AppUser (
    id          INTEGER PRIMARY KEY,
    username    VARCHAR UNIQUE,
    email       VARCHAR UNIQUE,
    password    VARCHAR,
    role        VARCHAR
);

INSERT INTO AppUser VALUES(1,'admin','admin@domain.com','admin','ROLE_ADMIN');

-- -----------------------
-- Bathroom Table
-- -----------------------
CREATE TABLE Bathroom (id INTEGER PRIMARY KEY, building VARCHAR, floor INTEGER, location VARCHAR, gender CHARACTER, stallCount INTEGER, urinalCount INTEGER, ratings VARCHAR);

INSERT INTO Bathroom VALUES (1, "Ivey_Building", 1, "43.004461059421644, -81.2775063228374", 'm', 4, 3, '');
INSERT INTO Bathroom VALUES (2, "Ivey_Building", 1, "43.0044210977688, -81.2774867068221", 'f', 4, 0, '');
INSERT INTO Bathroom VALUES (3, "Ivey_Building", 1, "43.0044292950326, -81.2785445705308", 'm', 2, 2, '');
INSERT INTO Bathroom VALUES (4, "Ivey_Building", 1, "43.004405727894955, -81.2786076220085", 'f', 4, 0, '');
INSERT INTO Bathroom VALUES (5, "Ivey_Building", 2, "43.00443762256217, -81.27748547574704", 'm', 4, 3, '');
INSERT INTO Bathroom VALUES (6, "Ivey_Building", 2, "43.00441399256533, -81.27743979284249", 'f', 4, 0, '');
INSERT INTO Bathroom VALUES (7, "Ivey_Building", 2, "43.00451721597472, -81.27849985772822", 'm', 1, 1, '');
INSERT INTO Bathroom VALUES (8, "Ivey_Building", 2, "43.00449612985443, -81.27849918717598", 'f', 2, 0, '');
INSERT INTO Bathroom VALUES (9, "Ivey_Building", 3, "43.00444248813663, -81.27750539795498", 'm', 3, 2, '');
INSERT INTO Bathroom VALUES (10, "Ivey_Building", 3, "43.004402045063216, -81.27750166127225", 'f', 4, 0, '');
INSERT INTO Bathroom VALUES (11, "Ivey_Building", 3, "43.00414892991265, -81.27832009518386", 'b', 2, 0, '');
INSERT INTO Bathroom VALUES (12, "Ivey_Building", 3, "43.004126594702534, -81.27831217699067", 'b', 2, 0, '');

INSERT INTO Bathroom VALUES (13, "University_College", 1, "43.004461059421644, -81.2775063228374", 'm', 4, 3, '');
INSERT INTO Bathroom VALUES (14, "University_College", 1, "43.0044210977688, -81.2774867068221", 'f', 4, 0, '');

INSERT INTO Bathroom VALUES (15, "Middlesex_College", 2, "43.00952121129927, -81.27034139152056", 'm', 2, 4, '');
INSERT INTO Bathroom VALUES (16, "Middlesex_College", 2, "43.009489053766245, -81.2703155228848", 'f', 6, 0, '');
INSERT INTO Bathroom VALUES (17, "Middlesex_College", 2, "43.00952972358097, -81.27028965424532", 'b', 2, 2, '');
INSERT INTO Bathroom VALUES (18, "Middlesex_College", 2, "43.00904168397958, -81.27024567756591", 'm', 4, 4, '');
INSERT INTO Bathroom VALUES (19, "Middlesex_College", 3, "43.009508563203404, -81.27035166937257", 'm', 3, 3, '');
INSERT INTO Bathroom VALUES (20, "Middlesex_College", 3, "43.00904536669415, -81.27023953923184", 'f', 4, 0, '');
INSERT INTO Bathroom VALUES (21, "Middlesex_College", 4, "43.00952972358097, -81.27028965424532", 'b', 3, 2, '');
INSERT INTO Bathroom VALUES (22, "Middlesex_College", 5, "43.00951990833393, -81.27034081132147", 'm', 2, 4, '');

-- -----------------------
-- Building Table
-- -----------------------
CREATE TABLE Building (name VARCHAR PRIMARY KEY, location VARCHAR);

INSERT INTO Building VALUES ("Ivey_Building", "43.004379707504405, -81.27719654522188");
INSERT INTO Building VALUES ("University_College", "43.008427372331774, -81.27331583172878");
INSERT INTO Building VALUES ("Middlesex_College", "43.00965542351857, -81.27022994522166");

-- -----------------------
-- Ratings Table
-- -----------------------
CREATE TABLE Rating (id INTEGER PRIMARY KEY, uploader VARCHAR, bathroomId INT, overallRating INT, cleanlinessRating INT, textReview VARCHAR);

INSERT INTO Rating VALUES (1,"bathroomreviwer1", 15, 4, 5, "very clean, private bathroom highly reccommend");
INSERT INTO Rating VALUES (2,"bathroomreviwer1", 15, 3, 3, "standard bathroom, B+");
