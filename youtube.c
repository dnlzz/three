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
  
  n = find_length(head);  
  printf("%d clips\n",n); //69 clips
  print_lst(head);    /* prints the table */ 
  
  return 0;
}

struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[4];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;

  // hp=malloc(sizeof(struct clip));

  // hp=head;
  
  fp = fopen ( fn, "r" );
   if ( fp != NULL )
   {
     while ( fgets ( line, sizeof(line), fp ) != NULL ) /* read a line */
      {
        split_line(fields, line);
	//potentially go through fields array and replace "COMMA" with ","
	//fields contains 4 fields, now pass to append make them into a struct
	//and add to list.
	head = append(hp, fields); //or hp =    cp =??
	hp = head;
        //cnt++;
	/*/testerr
	for (int i=0; i < 4; i++) { //less than tok 'cnt'
	   printf("field at index %d : %s", i, fields[i]); 
	 }
	//end tester */

	//append();
      }
      fclose ( fp );
   }
   else
   {
      //error
   }

   // hp = head;
   
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
  // printf("%d : %s\n", i, token); 
  i++;

  token=strtok(NULL, delim);
  
  while (token != NULL) {
    fields[i]=token;
    //printf("%d : %s\n", i, token); 
    i++;
    token=strtok(NULL, delim);
  }

  /* 
     call strtok(line, delim);
     repeat until strtok returns NULL using strtok(NULL, delim);
 */
}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp, *tp;  //temp ptr?

  
  
  //printf("hp: %x,  &hp: %x\n", hp, &hp);
  
  tp = malloc(sizeof(struct clip));
  int iViews = atoi(*five);
  
  if (hp == NULL) {
    tp->views = iViews;
    tp->user = *(five + 1);
    tp->id = *(five + 2);
    tp->title = *(five + 3);
    tp->next = NULL;    
    hp = tp;
  } else {
     cp = hp;
  
    while(cp->next != NULL) {
      cp = cp->next;
    }
    
    cp->next = tp;
  }
  
  //  printf("tp: %x,  &tp: %x,  *tp: %x\n", tp, &tp, *tp);
  // printf("hp: %x,  &hp: %x,  *hp: %x\n\n", hp, &hp, *hp);
  
  /*
  tp = malloc(sizeof(struct clip));
  int iViews = atoi(*five);

  tp->views = iViews;
  tp->user = *(five + 1);
  tp->id = *(five + 2);
  tp->title = *(five + 3);
  tp->next = NULL;

  printf("%d,%s,%s,%s,%x\n",tp->views,tp->user,tp->id,tp->title, tp->next);
  cp = hp;
  
    while(cp->next != NULL) {
      printf("WHILE?");
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
  
  //  free(tp);
    
  return hp;
}

void print_lst(struct clip *hp) {
  struct clip *cp;
  
  cp = hp;
  while (cp) {
    printf("%d,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title);
    cp = cp->next;
  }
  
  /* 
     use a while loop and the statement below to print the list
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  */
}

int find_length(struct clip *hp) {
  int count = 0;

  struct clip *cp;

  cp = hp;

  while (cp) {
    count++;
    cp=cp->next;
  }

  return count;
}


/* end */
