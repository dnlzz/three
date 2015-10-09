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
  
  fp = fopen ( fn, "r" );
   if ( fp != NULL )
   {
     while ( fgets ( line, sizeof(line), fp ) != NULL ) /* read a line */
      {
        split_line(fields, line);
	       head = append(hp, fields);
	       hp = head;
      }
      fclose ( fp );
   }
   else
   {
      //error
   }
   
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

  token=strtok(NULL, delim);
  
  while (token != NULL) {
    fields[i]=token;
    i++;
    token=strtok(NULL, delim);
  }

}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp, *tp;  //temp ptr?
  
  tp = malloc(sizeof(struct clip));
  int iViews = atoi(*five);
  char *users = malloc(sizeof(*(five+1)));
  char *id2 = malloc(sizeof(*(five+2)));
  char *title2 = malloc(strlen( *(five+3) ) + 1 );

  strcpy(users, *(five+1));
  strcpy(id2, *(five+2));
  strcpy(title2, *(five+3));
  
  tp->views = iViews; 
  tp->user = users;   
  tp->id = id2;       
  tp->title = title2;
  tp->next = NULL;   
  
  if (hp == NULL) {
    head = hp = tp;
  } else {
    cp = hp;
  
    while(cp->next != NULL) {
      cp = cp->next;
    }
    
    cp->next = tp;
  }
    
  return hp;
}

void print_lst(struct clip *hp) {
  struct clip *cp;
  
  cp = hp;
  while (cp) {
    printf("%d  %s  %s  %s\n", cp->views, cp->user, cp->id, cp->title);
    cp = cp->next;
  }

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
