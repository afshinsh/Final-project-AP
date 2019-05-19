#ifndef MANAGER_H
#define MANAGER_H

#include "customer.h"
#include "comment.h"
#include "exceptions.h"
#include "publisher.h"
#include "comment.h"

class manager
{
public:
  manager();
  void process_users();
  void process_begin_of_command();
  void skip_space();
  void set_first_part();
  void set_second_part();
  void process_command();
  void process_GET_command();
  void DELETE_comments();
  void process_POST_command();
  void check_DELETE_second_part();
  void process_command_buy(string &film_id);
  void POST_film();
  void POST_signup();
  void process_command_money(string &amount);
  void POST_money();
  void process_DELETE_command();
  void process_PUT_command();
  void GET_followers();
  void check_inputs_for_rate(string score, string film_id);
  void POST_followers();
  void DELETE_film();
  void set_recommendation(film* f);
  void charge_account();
  void process_command_comments(string &film_id, string &content);
  void POST_rate();
  void process_command_delete(string &film_id);
  void process_command_signup(string &email, string &username
, string &password, string &age, string &publisher);
  void check_command_for_PUT(string &name, string &year, string &price
  , string &summary, string &length, string &director, string &film_id);
  void initialize_film(string name, string year, string length
  , string price, string summary, string director);
  void process_command_followers(string &user_id);
  void check_GET_second_part();
  void set_info(string &info);
  void show_head_followers();
  void initialize_user(string &email, string &username
  , string &password, string &age, string &publisher);
  void find_user(string username, string password);
  void POST_login();
  void process_command_rate(string &film_id,string &score);
  void reset();
  void show_details(film* Film);
  void process_command_login(string &username, string &password);
  void POST_replies();
  void show_features(film* Film);
  void show_comments(film* Film);
  void show_recommendation(film* Film);
  bool check_is_not_integer(string s);
  void regist_film();
  void process_command_delete_comments(string &film_id,string &comment_id);
  void set_command(string _command) ;
  void check_POST_second_part();
  void check_first_part();
  string achieve_part();
  void check_PUT_second_part();
  void PUT_film();
  void check_user_for_command();
  void catch_money();
  void pay_money(double percent, int i);
  void check_repeated_username(string username);
  void process_command_replies(string &film_id, string &comment_id
  , string &content);
  void process_command_GET_films(string &name, string &min_year, string &price
, string &max_year, string &min_rate, string &director);
  void GET_film();
  void POST_buy();
  void GET_films();
  void POST_comments();
  void check_for_buy(string film_id);
private:
  vector<film*> films;
  vector<customer*> users;
  vector<customer*> customers;
  vector<customer*> publishers;
  vector<film*> recommendation_films;
  vector<film*> search_result;
  string command;
  int command_chars_counter = 0;
  int ID_counter = 1;
  int ID_counter_film = 1;
  customer* current_user = NULL;
  string first_part = EMPTEY_STRING ;
  string second_part = EMPTEY_STRING;
  string sentence_part;
  int property = 0;
};


#endif