#include <iostream> 
#include <sqlite3.h> 
using namespace std;
int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ":" << argv[i] << endl;
        cout << endl;
    }
    return 0;
}

void create(string sql1, string sql2, string sql3, string sql4, string sql5, int rc, sqlite3* db, char* errorMessage)
{
    sql1 = " CREATE TABLE MODULES (" \
            "ID INT PRIMARY KEY NOT NULL,"\
            "NAME TEXT NOT NULL);";
            "YEAR_TAUGHT INT NOT NULL);";
            "SIZE INT NOT NULL);";

    sql2 = " CREATE TABLE CLASSES (" \
            "MODULEID INT FOREIGN KEY  NOT NULL,"\
            "ROOMID INT FOREIGN KEY  NOT NULL,"\
            "NAME PRIMARY KEY TEXT NOT NULL);";
            "TIME_OF_DAY INT NOT NULL);";
            "LECTURER TEXT NOT NULL);";
            "SIZE INT NOT NULL);";

    sql3 = " CREATE TABLE LECTURERS (" \
            "CLASSNAME TEXT FOREIGN KEY  NOT NULL,"\
            "NAME TEXT PRIMARY KEY NOT NULL);";

    sql4 = " CREATE TABLE STUDENTS (" \
            "MODULEID INT FOREIGN KEY  NOT NULL,"\
            "STUDENTID VARCHAR PRIMARY KEY NOT NULL);";
            "TITLE TEXT NOT NULL);";
            "F_NAME TEXT NOT NULL);";
            "L_NAME TEXT NOT NULL);";
            "GENDER TEXT NOT NULL);";
            "DOB INT NOT NULL);";
            "NATIONALITY TEXT NOT NULL);";
            "PHONENR INT NOT NULL);";

    sql5 = " CREATE TABLE ROOMS (" \
            "ROOMID INT PRIMARY KEY  NOT NULL);";
            "NAME TEXT NOT NULL);";
            "LOCATION TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql1.c_str(), callback, 0, &errorMessage);
    rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &errorMessage);
    rc = sqlite3_exec(db, sql3.c_str(), callback, 0, &errorMessage);
    rc = sqlite3_exec(db, sql4.c_str(), callback, 0, &errorMessage);
    rc = sqlite3_exec(db, sql5.c_str(), callback, 0, &errorMessage);

}

void insert1(string sql1,int rc, sqlite3* db, char* errorMessage) {

    sql1 = "INSERT INTO MODULES('ID','NAME','YEAR_TAUGHT','SIZE') VALUES ('4000','PROGRAMMING AND ALGORITHMS','1','400');";
    rc = sqlite3_exec(db, sql1.c_str(), callback, 0, &errorMessage);

    sql1 = "INSERT INTO MODULES('ID','NAME','YEAR_TAUGHT','SIZE') VALUES ('4001','SOFTWARE DESIGN','1', '200');";
    rc = sqlite3_exec(db, sql1.c_str(), callback, 0, &errorMessage);

	sql1 = "INSERT INTO MODULES('ID','NAME','YEAR_TAUGHT','SIZE') VALUES ('4002','MATHMATICS','1', '400');";
    rc = sqlite3_exec(db, sql1.c_str(), callback, 0, &errorMessage);

    .
        .
        .


}

void insert2(string sql2, int rc, sqlite3* db, char* errorMessage) {


    sql2 = "INSERT INTO CLASSES('MODULEID','ROOM ID','NAME','TIME_OF_THE_DAY','LECTURER','SIZE') VALUES ('4000', 'ASG31', 'WEEK3', '1600', 'DR MATTHEW ENGLAND', '400');";
    rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &errorMessage);


    sql2 = "INSERT INTO CLASSES('MODULEID','ROOM ID','NAME','TIME_OF_THE_DAY','LECTURER','SIZE') VALUES ('4001', 'EC214', 'WEEK3', '1700');";
    rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &errorMessage);
	
	sql2 = "INSERT INTO CLASSES('MODULEID','ROOM ID','NAME','TIME_OF_THE_DAY','LECTURER','SIZE') VALUES ('4002', 'ECG24', 'WEEK3', '1200');";
    rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &errorMessage);

    .
    .
    .
    

}

void insert3(string sql3, int rc, sqlite3* db, char* errorMessage) {


    sql3 = "INSERT INTO LECTURERS('CLASSNAME','NAME') VALUES ( 'CS', 'DR MATTHEW ENGLAND');";
    rc = sqlite3_exec(db, sql3.c_str(), callback, 0, &errorMessage);
	
	sql3 = "INSERT INTO LECTURERS('CLASSNAME','NAME') VALUES ( 'CS', 'DR YIH LING');";
    rc = sqlite3_exec(db, sql3.c_str(), callback, 0, &errorMessage);
	
	sql3 = "INSERT INTO LECTURERS('CLASSNAME','NAME') VALUES ( 'CS', 'SUSANNE HORN');";
    rc = sqlite3_exec(db, sql3.c_str(), callback, 0, &errorMessage);

}

void insert4(string sql4, int rc, sqlite3* db, char* errorMessage) {


    sql4 = "INSERT INTO STUDENTS('STUDENTID','TITLE','F_NAME', 'L_NAME', 'GENDER','DOB','NATIONALITY', 'PHONENR') VALUES ('9241785', 'MS', 'BEATRIZ', 'GARCIA', 'FEMALE', '0611200', 'PORTUGUESE', '07798687815');";
    rc = sqlite3_exec(db, sql4.c_str(), callback, 0, &errorMessage);
	
    sql4 = "INSERT INTO STUDENTS('STUDENTID','TITLE','F_NAME', 'L_NAME', 'GENDER','DOB','NATIONALITY', 'PHONENR') VALUES ('9241764', 'MR', 'FERNANDO', 'GOMES', 'MALE', '0208299', 'PORTUGUESE', '07798687843');";
    rc = sqlite3_exec(db, sql4.c_str(), callback, 0, &errorMessage);


    sql4 = "INSERT INTO STUDENTS('STUDENTID','TITLE','F_NAME', 'L_NAME', 'GENDER','DOB','NATIONALITY', 'PHONENR') VALUES ('9353565', 'MS', 'PATRIXIA', 'PAPURA', 'FEMALE', '0610200', 'ROMANIAN', '07324543815');";
    rc = sqlite3_exec(db, sql4.c_str(), callback, 0, &errorMessage);


}

void insert5(string sql5, int rc, sqlite3* db, char* errorMessage) {


    sql5 = "INSERT INTO ROOMS('ROOMID','NAME','LOCATION') VALUES ('EC214', 'LECTURE', 'CAMPUS' );";
    rc = sqlite3_exec(db, sql5.c_str(), callback, 0, &errorMessage);
	
	sql5 = "INSERT INTO ROOMS('ROOMID','NAME','LOCATION') VALUES ('EC230', 'LAB', 'CAMPUS' );";
    rc = sqlite3_exec(db, sql5.c_str(), callback, 0, &errorMessage);

	sql5 = "INSERT INTO ROOMS('ROOMID','NAME','LOCATION') VALUES ('EC18', 'LAB', 'CAMPUS' );";
    rc = sqlite3_exec(db, sql5.c_str(), callback, 0, &errorMessage);


}


int main(int argc, char** argv)
{
    sqlite3* db;
    char* errorMessage = 0;
    int rc;
    string sql1, sql2, sql3, sql4, sql5;
    rc = sqlite3_open("modules.db", &db);
    if (rc)
    {
        cout << "DB Error:" << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    create(sql1, sql2, sql3, sql4, sql5, rc,  db, errorMessage);

    insert1(sql1, rc, db, errorMessage);
    insert2(sql1, rc, db, errorMessage);
    insert3(sql1, rc, db, errorMessage);
    insert4(sql1, rc, db, errorMessage);
    insert5(sql1, rc, db, errorMessage);


    sqlite3_close(db);


    return (0);
}
