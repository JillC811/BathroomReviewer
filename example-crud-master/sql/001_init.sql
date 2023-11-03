
CREATE TABLE AppUser (
    id          INTEGER PRIMARY KEY,
    username    VARCHAR UNIQUE,
    email       VARCHAR UNIQUE,
    password    VARCHAR,
    role        VARCHAR
);

INSERT INTO AppUser
(username, email, password, role) VALUES ('admin', 'admin@domain.com', 'admin', 'ROLE_ADMIN');

CREATE TABLE Bathroom (
     id INTEGER PRIMARY KEY,
     building VARCHAR,
     floor INTEGER,
     location VARCHAR,
     gender CHARACTER,
     stallCount INTEGER,
     urinalCount INTEGER,
     rating INTEGER
);

INSERT INTO Bathroom VALUES (0, "UCC", 1, "0.000,0.000", 'F', 4, 0, 4)

CREATE TABLE Building (
    name VARCHAR PRIMARY KEY,
    location VARCHAR
);

INSERT INTO Building VALUES ("UCC", "0.000,0.000");