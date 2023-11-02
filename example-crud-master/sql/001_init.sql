
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

INSERT INTO Bathroom (id, buildling, floor, location, gender, stallCount, urinalCount, rating)
VALUES (0, "UCC", 1, "0.000,0.000", 'F', 4, 0, 4)
