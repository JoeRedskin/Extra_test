#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <stdio.h>
#include<string.h>
#include<fcntl.h>
extern "C" {
#include "common.h"
#include "text/text.h"
#include "text/_text.h"
#define STDOUT 1
}
TEST (abc, test1)
{
    text txt = create_text();
    ASSERT_EQ(pos_return(txt), 0);
}
/*TEST(protest, null_file)
{
     int fptr;
     int oldstdout;
     fptr = open("DUMMY.FIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
     oldstdout = dup(STDOUT);
     dup2(fptr,STDOUT);
     close(fptr);

     char *filedir=(char*)malloc(1024);
     sprintf(filedir, "%s/load.k", TESTIDIR);

     text txt = create_text();
     load(txt, filedir);
     dup2(oldstdout,STDOUT);

     FILE *t;
     t = fopen("DUMMY.FIL","rw");
     if(t == NULL){
            FAIL();
            return;
     }
     char *buf = (char*)malloc(sizeof(char)*512);
     int readcount = fread(buf,1,512,t);

     FILE *d;

     sprintf(filedir, "%s/fail.txt", TESTIDIR);
     d =fopen(filedir,"rw");

     if(d == NULL){
            FAIL();
            return;
     }
     char *buf2 = (char*)malloc(sizeof(char)*512);
     int readcount2 = fread(buf2,1,512,d);
     fclose(t);
     fclose(d);
     ASSERT_EQ(readcount,readcount2);

}*/

TEST(protest, show)
{
     int fptr;
     int oldstdout;

     fptr = open("DUMMY.BIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
     oldstdout = dup(STDOUT);
     dup2(fptr,STDOUT);

     char *filedir=(char*)malloc(1024);
     sprintf(filedir, "%s/load.txt", TESTIDIR);

     text txt = create_text();
     load(txt, filedir);
     show(txt);


close(fptr);
dup2(oldstdout,STDOUT);
     FILE *t2;
     t2 = fopen("DUMMY.BIL","rw");
     if(t2 == NULL){
            FAIL();
            return;
     }
     char *buf = (char*)malloc(sizeof(char)*512);
     int readcount = fread(buf,1,512,t2);

     FILE *d2;
     sprintf(filedir, "%s/proveka.txt", TESTIDIR);
     d2 =fopen(filedir,"rw");

     if(d2 == NULL){
            FAIL();
            return;
     }
     char *buf2 = (char*)malloc(sizeof(char)*512);
     int readcount2 = fread(buf2,1,512,d2);
     fclose(t2);
     fclose(d2);
     ASSERT_EQ(readcount,readcount2);

}

TEST(protest, pp_first_line)
{
     int fptr;
     int oldstdout;
     int i=0;
     fptr = open("DUMMY.PIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
     oldstdout = dup(STDOUT);
     dup2(fptr,STDOUT);
     close(fptr);

     char *filedir=(char*)malloc(1024);
     sprintf(filedir, "%s/load.txt", TESTIDIR);

     text txt = create_text();
     load(txt, filedir);
     c_to_pos(txt,0,0);
     pp(txt,(char *)"good");


     show(txt);
     dup2(oldstdout,STDOUT);

     FILE *t2;
     t2 = fopen("DUMMY.PIL","rw");
     if(t2 == NULL){
            FAIL();
            return;
     }
     char *buf1 = (char*)malloc(sizeof(char)*512);

     int readcount =  0;
     while(!feof(t2)){
     readcount+=fread(buf1,1,512,t2);
        }
     FILE *d2;

     sprintf(filedir, "%s/pp_first_line.txt", TESTIDIR);
     d2 =fopen(filedir,"rw");

     if(d2 == NULL){
            FAIL();
            return;
     }
     char *buf2 = (char*)malloc(sizeof(char)*512);
     int readcount2 = 0;
     while(!feof(d2)){
     readcount2+=fread(buf2,1,512,d2);
        }
   /*while(!feof(t2) && !feof(d2)){
        char* k1 = fgets(buf1, 512, t2);
        char* k2 = fgets(buf2, 512, d2);
        if(k1==k2){*/
         for(i=0;i<512;i++){
             if(buf1[i] != buf2[i])
                 FAIL();
         //}
         /**buf1 = "";
         *buf2 = "";*/
   //}
}

     fclose(t2);
     fclose(d2);
     ASSERT_EQ(readcount,readcount2);
     while(!feof(d2) && !feof(t2)){

}
}

TEST(protest, pp_second_line)
{
     int fptr;
     int oldstdout;
     int i=0;
     fptr = open("DUMMY.MIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
     oldstdout = dup(STDOUT);
     dup2(fptr,STDOUT);
     close(fptr);

     char *filedir=(char*)malloc(1024);
     sprintf(filedir, "%s/load.txt", TESTIDIR);

     text txt = create_text();
     load(txt, filedir);
     c_to_pos(txt,1,0);
     pp(txt,(char *)"good");


     show(txt);
     dup2(oldstdout,STDOUT);

     FILE *t2;
     t2 = fopen("DUMMY.MIL","rw");
     if(t2 == NULL){
            FAIL();
            return;
     }
     char *buf1 = (char*)malloc(sizeof(char)*512);

     int readcount =  0;
     while(!feof(t2)){
     readcount+=fread(buf1,1,512,t2);
        }
     FILE *d2;

     sprintf(filedir, "%s/pp_second_line.txt", TESTIDIR);
     d2 =fopen(filedir,"rw");

     if(d2 == NULL){
            FAIL();
            return;
     }
     char *buf2 = (char*)malloc(sizeof(char)*512);
     int readcount2 = 0;
     while(!feof(d2)){
     readcount2+=fread(buf2,1,512,d2);
        }
   /*while(!feof(t2) && !feof(d2)){
        char* k1 = fgets(buf1, 512, t2);
        char* k2 = fgets(buf2, 512, d2);
        if(k1==k2){*/
         for(i=0;i<512;i++){
             if(buf1[i] != buf2[i])
                 FAIL();
         //}
         /**buf1 = "";
         *buf2 = "";*/
  // }
}


     fclose(t2);
     fclose(d2);
     ASSERT_EQ(readcount,readcount2);
     while(!feof(d2) && !feof(t2)){

}
}


/*TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 5);
    ASSERT_EQ(fibonachi(10), 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}
*/
#endif // FIBONACHI_H
