#include "publisher.h"


publisher::publisher(string _email, string _username, string _password
, string _age, int _ID_counter, bool _publisher) : customer(_email, 
_username, _password, _age, _ID_counter, _publisher) {}

void publisher::regist_new_film(film* new_film)
{
  my_films.push_back(new_film);
}

void publisher::set_followers(customer* new_follower)
{
  for(int i = 0;i < followers.size(); i++)
  {
    if(new_follower->get_ID() == followers[i]->get_ID())
      return;
  }
  followers.push_back(new_follower);
}

void publisher::edit_films(string name, string year, string price
, string summary, string length, string director, int film_id)
{
  for(int i = 0;i < my_films.size(); i++)
  {
    if(my_films[i] != NULL && my_films[i]->get_ID() == film_id)
    {
      if(name != EMPTEY_STRING)
        my_films[i]->set_name(name);
      if(year != EMPTEY_STRING)
        my_films[i]->set_year(year);
      if(price != EMPTEY_STRING)
        my_films[i]->set_price
(price);
      if(summary != EMPTEY_STRING)
        my_films[i]->set_summary(summary);
      if(length != EMPTEY_STRING)
        my_films[i]->set_length(length);
      if(director != EMPTEY_STRING)
        my_films[i]->set_director(director);
      return;
    }
  }
  throw PermissionDenied();
}

void publisher::show_followers()
{
  for(int i = 0;i < followers.size();i++)
    cout<<i + 1<<". "<<followers[i]->get_ID()<<" | "<<
    followers[i]->get_username()<<" | "<<followers[i]->get_email()<<endl;
}

void publisher::delete_film(int film_id)
{
  for(int i = 0 ;i < my_films.size(); i++)
  {
    if(my_films[i] != NULL && my_films[i]->get_ID() == film_id)
    {
      my_films[i] = NULL;
      return;
    }
  }
  throw PermissionDenied();
}