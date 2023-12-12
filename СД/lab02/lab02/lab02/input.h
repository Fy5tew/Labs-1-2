#pragma once

#include <string>

#include "datatypes.h"
#include "database.h"


std::string inputString(std::string placeholder = "");


int inputInteger(std::string placeholder = "");


float inputFloat(std::string placeholder = "");


Group inputGroup(Database& db);


void updateGroup(Database& db, int group_id);


Lecturel inputLecturel(Database& db);


void updateLecturel(Database& db, int lecturel_id);


Subject inputSubject(Database& db);


void updateSubject(Database& db, int subject_id);


Info inputInfo(Database& db);


void updateInfo(Database& db, int info_id);
