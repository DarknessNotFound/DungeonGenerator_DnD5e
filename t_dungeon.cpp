//Programmer: DarkenessNotFound
//File:       t_dungeon.cpp
//Date:       3/15/2021
//Purpose:    The template for all of the functions of the dungeon class

#include "header.h"
#include <iostream>
using namespace std;

room dungeon::generate_room(const short room_id)
{ //Temporary Setup for all the rooms for testing purposes
  room c_room;
  c_room.m_length = 10;
  c_room.m_height = 10;
  c_room.m_num_exits = 2;
  
  c_room.m_low_l.x = 12*(room_id + 1);
  c_room.m_low_l.y = 50; 
  c_room.m_low_r.x = c_room.m_low_l.x + c_room.m_length;
  c_room.m_low_r.y = c_room.m_low_l.y;
  c_room.m_upp_l.x = c_room.m_low_l.x;
  c_room.m_upp_l.y = c_room.m_low_l.y + c_room.m_height;
  c_room.m_upp_r.x = c_room.m_low_l.x + c_room.m_length;
  c_room.m_upp_r.y = c_room.m_low_l.y + c_room.m_height;
  return c_room;
}

void dungeon::generate()
{
  for (int i = 0; i < m_num_rooms; i++)//Generate Rooms
  {
    m_rooms[i] = generate_room(i);
  }
  return;
}

void dungeon::print_dung()
{
  
  return;
}

void dungeon::print_dung_data()
{
  cout << "Outputing Dungeon Data...." << endl;
  for(int i = 0; i < m_num_rooms; i++)
  {
    cout << "  Room #" << i+1 << ":" << endl;
    cout << "    Length:     " << m_rooms[i].m_length << endl;
    cout << "    Heigth:     " << m_rooms[i].m_heigth << endl; 
    cout << "    Low Left X: " << m_rooms[i].m_low_l.x << endl;
    cout << "    Low Left Y: " << m_rooms[i].m_low_l.y << endl;
  }
}
