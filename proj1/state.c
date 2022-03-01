#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake_utils.h"
#include "state.h"

/* Helper function definitions */
static char get_board_at(game_state_t* state, int x, int y);
static void set_board_at(game_state_t* state, int x, int y, char ch);
static bool is_tail(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static int incr_x(char c);
static int incr_y(char c);
static void find_head(game_state_t* state, int snum);
static char next_square(game_state_t* state, int snum);
static void update_tail(game_state_t* state, int snum);
static void update_head(game_state_t* state, int snum);

/* Helper function to get a character from the board (already implemented for you). */
static char get_board_at(game_state_t* state, int x, int y) {
  return state->board[y][x];
}

/* Helper function to set a character on the board (already implemented for you). */
static void set_board_at(game_state_t* state, int x, int y, char ch) {
  state->board[y][x] = ch;
}

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: Implement this function.
    game_state_t* d_state = (game_state_t*) malloc(sizeof(game_state_t));
    d_state->x_size=14,d_state->y_size=10;
    if(!(d_state->board= (char**) malloc(sizeof(char*)*10)))exit(1);
    for(size_t i=0;i<10;i++)
        if(!(d_state->board[i] = (char *) malloc(sizeof(char) * 15)))exit(1);
    strcpy(d_state->board[0],"##############\n");
    strcpy(d_state->board[1],"#            #\n");
    strcpy(d_state->board[2],"#        *   #\n");
    strcpy(d_state->board[3],"#            #\n");
    strcpy(d_state->board[4],"#   d>       #\n");
    strcpy(d_state->board[5],"#            #\n");
    strcpy(d_state->board[6],"#            #\n");
    strcpy(d_state->board[7],"#            #\n");
    strcpy(d_state->board[8],"#            #\n");
    strcpy(d_state->board[9],"##############\n");
    if(!(d_state->snakes=(snake_t*) malloc(sizeof(snake_t))))exit(1);
    d_state->snakes[0].head_x=5,d_state->snakes[0].head_y=4;
    d_state->snakes[0].tail_x=4,d_state->snakes[0].tail_y=4;
    d_state->snakes[0].live=true;
    d_state->num_snakes=1;
  return d_state;
}

/* Task 2 */
void free_state(game_state_t* state) {
  // TODO: Implement this function.
    for(size_t i=0;i<10;i++)free(state->board[i]);
    free(state->snakes);
    free(state->board);
    free(state);
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: Implement this function.
    for(size_t i=0;i<state->y_size;i++)fprintf(fp,"%s", state->board[i]);
}

/* Saves the current state into filename (already implemented for you). */
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */
static bool is_tail(char c) {
  // TODO: Implement this function.
  return true;
}

static bool is_snake(char c) {
  // TODO: Implement this function.
  return true;
}

static char body_to_tail(char c) {
  // TODO: Implement this function.
  return '?';
}

static int incr_x(char c) {
  // TODO: Implement this function.
  return 0;
}

static int incr_y(char c) {
  // TODO: Implement this function.
  return 0;
}

/* Task 4.2 */
static char next_square(game_state_t* state, int snum) {
  // TODO: Implement this function.
    int cur_head_x=state->snakes[snum].head_x,cur_head_y=state->snakes[snum].head_y;
    switch (get_board_at(state,cur_head_x,cur_head_y)) {
        case '>':
            return get_board_at(state,cur_head_x+1,cur_head_y);
        case '<':
            return get_board_at(state,cur_head_x-1,cur_head_y);
        case '^':
            return get_board_at(state,cur_head_x,cur_head_y-1);
        case 'v':
            return get_board_at(state,cur_head_x,cur_head_y+1);
        default:
            exit(3);
    }
}

/* Task 4.3 */
static void update_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
    int cur_head_x=state->snakes[snum].head_x,cur_head_y=state->snakes[snum].head_y;
    switch (get_board_at(state,cur_head_x,cur_head_y)) {
        case '>':
            set_board_at(state,cur_head_x+1,cur_head_y,'>');
            state->snakes[snum].head_x++;
            break;
        case '<':
            set_board_at(state,cur_head_x-1,cur_head_y,'<');
            state->snakes[snum].head_x--;
            break;
        case '^':
            set_board_at(state,cur_head_x,cur_head_y-1,'^');
            state->snakes[snum].head_y--;
            break;
        case 'v':
            set_board_at(state,cur_head_x,cur_head_y+1,'v');
            state->snakes[snum].head_y++;
            break;
        default:
            exit(4);
    }
}

static void set_tail(game_state_t* state,int n_tail_x,int n_tail_y){
    switch (get_board_at(state,n_tail_x,n_tail_y)) {
        case '>':
            return set_board_at(state,n_tail_x,n_tail_y,'d');
        case '<':
            return set_board_at(state,n_tail_x,n_tail_y,'a');
        case '^':
            return set_board_at(state,n_tail_x,n_tail_y,'w');
        case 'v':
            return set_board_at(state,n_tail_x,n_tail_y,'s');
        default:
            exit(2);
    }
}

/* Task 4.4 */
static void update_tail(game_state_t* state, int snum) {
  // TODO: Implement this function.
    int cur_tail_x=state->snakes[snum].tail_x,cur_tail_y=state->snakes[snum].tail_y;
    char tail_state = get_board_at(state,cur_tail_x,cur_tail_y);
    set_board_at(state,cur_tail_x,cur_tail_y,' ');
    switch (tail_state) {
        case 'w':
            set_tail(state,cur_tail_x,cur_tail_y-1);
            state->snakes[snum].tail_y--;
            break;
        case 'a':
            set_tail(state,cur_tail_x-1,cur_tail_y);
            state->snakes[snum].tail_x--;
            break;
        case 's':
            set_tail(state,cur_tail_x,cur_tail_y+1);
            state->snakes[snum].tail_y++;
            break;
        case 'd':
            set_tail(state,cur_tail_x+1,cur_tail_y);
            state->snakes[snum].tail_x++;
            break;
        default:
            exit(5);
    }
}

static bool check(char head,char n){
    if((head=='>')&&(n=='d'))return true;
    if((head=='<')&&(n=='a'))return true;
    if((head=='^')&&(n=='w'))return true;
    if((head=='v')&&(n=='s'))return true;
    return false;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  for(int i=0;i<state->num_snakes;i++){
      char n_state= next_square(state,i);
      int cur_head_x=state->snakes[i].head_x,cur_head_y=state->snakes[i].head_y;
      if(n_state=='*'){
          update_head(state,i);
          add_food(state);
      }
      else if(n_state==' '/*|| check(get_board_at(state,cur_head_x,cur_head_y),n_state)*/){
          update_head(state,i);
          update_tail(state,i);
      }
      else{
          set_board_at(state,cur_head_x,cur_head_y,'x');
          state->snakes[i].live=false;
      }
  }
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
    FILE* f = fopen(filename, "r");

    fflush(f);
    char* s= NULL;

    size_t len=1<<10;
    size_t read;
    if((read= getline(&s,&len,f))<0)exit(1);
    game_state_t* state = (game_state_t*) malloc(sizeof(game_state_t));
    state->x_size= strlen(s)-1;
    if(!(state->board=(char**) malloc(sizeof(char*)*(1<<10))))exit(1);
    if(!(state->board[0]=(char *) malloc(sizeof(char)*(state->x_size+4))))exit(1);
    strcpy(state->board[0],s);
    state->y_size=1;
    while((read= getline(&s,&len,f))!=-1){
        if(!(state->board[state->y_size]=(char*) malloc(sizeof(char)*(state->x_size+1))))exit(1);
        strcpy(state->board[state->y_size],s);
        state->y_size++;
    }
    free(s);
    fclose(f);
    return state;
}

/* Task 6.1 */
static void find_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
    int cur_x=state->snakes[snum].tail_x,cur_y= state->snakes[snum].tail_y;
    char cur_state= get_board_at(state,cur_x,cur_y);
    int checked[state->y_size][state->x_size];
    for(int i=0;i<state->y_size;i++)
        for(int j=0;j<state->x_size;j++)
            checked[i][j]=0;
    checked[cur_y][cur_x]=1;
    while (true){
        if(cur_state=='>'||cur_state=='d'){
            char n=get_board_at(state,cur_x+1,cur_y);
            if(n==' '||n=='*'||n=='#'|| checked[cur_y][cur_x+1])break;
            cur_x++;
            checked[cur_y][cur_x]=1;
        }
        else if(cur_state=='<'||cur_state=='a'){
            char n=get_board_at(state,cur_x-1,cur_y);
            if(n==' '||n=='*'||n=='#'|| checked[cur_y][cur_x-1])break;
            cur_x--;
            checked[cur_y][cur_x]=1;
        }
        else if(cur_state=='^'||cur_state=='w'){
            char n=get_board_at(state,cur_x,cur_y-1);
            if(n==' '||n=='*'||n=='#'|| checked[cur_y-1][cur_x])break;
            cur_y--;
            checked[cur_y][cur_x]=1;
        }
        else if (cur_state=='v'||cur_state=='s'){
            char n=get_board_at(state,cur_x,cur_y+1);
            if(n==' '||n=='*'||n=='#'|| checked[cur_y+1][cur_x])break;
            cur_y++;
            checked[cur_y][cur_x]=1;
        }
        else {
            exit(6);
        }
        cur_state= get_board_at(state,cur_x,cur_y);
    }
    state->snakes[snum].head_x=cur_x,state->snakes[snum].head_y=cur_y;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
    if(!(state->snakes=(snake_t*) malloc(sizeof(snake_t)*(1<<6))))exit(1);
    int num=0;
    for(size_t i=0;i<state->y_size;i++)
       for(size_t j=0;j<state->x_size;j++){
           char cur=get_board_at(state,j,i);
           if(cur=='w'||cur=='a'||cur=='s'||cur=='d'){
               state->snakes[num].tail_x=j;
               state->snakes[num].tail_y=i;
               find_head(state,num);
               state->snakes[num].live=true;
               num++;
           }
      }
    state->num_snakes=num;
  return state;
}
