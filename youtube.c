#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256

struct clip *build_a_lst();
struct clip *append();
int find_length();
void print_lst();
void split_line();

struct clip {
  int views;
  char *user;
  char *id;
  char *title;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  int n;
  head = build_a_lst(*(argv+1));
  
  //n = find_length(head);  
  //printf("%d clips\n",n); //69 clips
  //print_lst(head);    /* prints the table */ 
  
  return 0;
}

struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[4];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;

  fp = fopen ( fn, "r" );
   if ( fp != NULL )
   {
      while ( fgets ( line, sizeof(line), fp ) != NULL ) /* read a line */
      {
        split_line(fields, line);
        //potentially go through fields array and replace "COMMA" with ","
        append(head, fields); //or hp =    cp =??
        //cnt++;
	/*/testerr
        int i;
	for (i=0; i < 4; i++) { //less than tok 'cnt'
	   printf("field at index %d : %s", i, fields[i]); 
	 }
	//end tester */
      }
      fclose ( fp );
   }
   else
   {
      //error
   }

  // open fn -OK
  // while no more lines- OK
  // read a line- OK
  // split the line into four substrings/int and store them in a struct
  // append - add the struct at the end of the list
  // return the head pointer holding the list

  return hp;
}

/* fields will have four values stored upon return */
void split_line(char **fields,char *line) {
  int i=0;
  char *token, *delim;
  delim = ",\n";

  token=strtok(line, ",");
  fields[i]=token;
  i++;
  
  while (token != NULL) {
    token=strtok(NULL, delim);
    fields[i]=token;
    //printf("%s  ", token);    
    i++;
  }

  i=0;
  printf("\n");
  
  /* 
     call strtok(line, delim);
     repeat until strtok returns NULL using strtok(NULL, delim);
 */
}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp,*tp;  //temp ptr?

  tp = malloc(sizeof(struct clip));
  int iViews = atoi(*five);

  tp->views = iViews;
  tp->user = *(five + 1);
  tp->id = *(five + 2);
  tp->title = *(five + 3);

  printf("cp %x, hp %x", cp, hp);

  cp = hp;

  printf("cp %x, hp %x", cp, hp);

  while(cp->next != NULL) {
    cp = cp->next;
  }

  cp->next = tp;
  
  /* 
     malloc tp - OK
     set views using atoi(*five) - OK
     malloc for four strings.
     strcpy four strings to tp
     insert tp at the end of the list pointed by hp - OK
     use cp to traverse the list - OK
 */

  return hp;
}

void print_lst(struct clip *cp) {

  cp = head;
  while (cp) {
    printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title);
  }
  
  /* 
     use a while loop and the statement below to print the list
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  */
}

/* end */
