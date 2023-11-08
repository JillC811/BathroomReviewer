
# Overview

This project is "Yelp for bathrooms" on Western's campus.
This project is using the following oatpp modules:

- [oatpp](https://github.com/oatpp/oatpp) 
- [oatpp-swagger](https://github.com/oatpp/oatpp-swagger)
- [oatpp-sqlite](https://github.com/oatpp/oatpp-sqlite)

---

## Build and Run (using CMake)

### Pre Requirements

- `oatpp` 
- `oatpp-swagger`
- `oatpp-sqlite` with `-DOATPP_SQLITE_AMALGAMATION=ON` cmake flag.

**Note:** You may run `utility/install-oatpp-modules.sh` script to install required oatpp modules. Users may have issues with the script on Windows devices and instead have to install libraries manually.

### Build Project

```
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./crud-exe        # - run application.
```

---

## Endpoints 

Documentation Format:
|---|---|---|
|HTTP Method|URL|Description|

### User Service

|---|---|---|
|`POST`|http://localhost:8000/users | Create new User |
|`PUT`|http://localhost:8000/users/{userId} | Update User by ID |
|`GET`|http://localhost:8000/users/{userId} | Get User by ID |
|`DELETE`|http://localhost:8000/users/{userId} | Delete User by ID |
|`GET`|http://localhost:8000/users/offset/{offset}/limit/{limit} | Get All Users with Paging |

### Bathroom Service

|---|---|---|
|`POST`|http://localhost:8000/bathrooms | Create new building |
|`GET`|http://localhost:8000/bathrooms/offset/{offset}/limit/{limit} | Get all bathrooms |
|`GET`|http://localhost:8000/bathrooms/{bathroomId} | Get a bathroom by ID |
|`GET`|http://localhost:8000/bathrooms/building/{building} | Get all bathrooms in building |
|`PUT`|http://localhost:8000/bathrooms/{bathroomId} | Update bathroom by ID |
|`DELETE`|http://localhost:8000/bathrooms/{bathroomId} | Delete bathroom by ID |

### Building Service

|---|---|---|
|`POST`|http://localhost:8000/buildings | Create new building |
|`GET`|http://localhost:8000/buildings/offset/{offset}/limit/{limit} | Get all buildings |
|`GET`|http://localhost:8000/buildings/{buildingName} | Get a building by name |
|`PUT`|http://localhost:8000/buildings/{buildingName} | Update building by name |
|`DELETE`|http://localhost:8000/buildings/{buildingName} | Delete building by name |
