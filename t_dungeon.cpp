//Programmer: DarkenessNotFound
//File:       t_dungeon.cpp
//Date:       3/15/2021
//Purpose:    The template for all of the functions of the dungeon class

#include "header.h"
#include <iostream>
using namespace std;

bool dungeon::crn_on_row_exists(const int row)
{
  bool exists = false;
  for(int room_id = 0; room_id < m_num_rooms; room_id++)
  {
    if ((m_rooms[room_id].m_cnr.m_upp_l.y == row) ||
        (m_rooms[room_id].m_cnr.m_low_l.y == row) )
          exists = true;
  }
  return exists;
}

room dungeon::generate_room(const short room_id)
{ //Temporary Setup for all the rooms for testing purposes
  room c_room;
  c_room.m_length = 10;
  c_room.m_height = 10;
  c_room.m_num_exits = 2;

  c_room.m_cnr.m_low_l.x = 12*(room_id + 1);
  c_room.m_cnr.m_low_l.y = 50; 
  c_room.m_cnr.m_low_r.x = c_room.m_cnr.m_low_l.x + c_room.m_length;
  c_room.m_cnr.m_low_r.y = c_room.m_cnr.m_low_l.y;
  c_room.m_cnr.m_upp_l.x = c_room.m_cnr.m_low_l.x;
  c_room.m_cnr.m_upp_l.y = c_room.m_cnr.m_low_l.y - c_room.m_height;
  c_room.m_cnr.m_upp_r.x = c_room.m_cnr.m_low_l.x + c_room.m_length;
  c_room.m_cnr.m_upp_r.y = c_room.m_cnr.m_low_l.y - c_room.m_height;
  return c_room;
}

void dungeon::initilize_map()
{
  for(int row = 0; row < m_hgt; row++)
  {
    for(int clm = 0; clm < m_len;  clm++)
    {
      map_coords[row][clm] = ' ';
    }
  }
}

void dungeon::generate()
{
  initilize_map();
  for (int i = 0; i < m_num_rooms; i++)//Generate Rooms
  {
    m_rooms[i] = generate_room(i);
  }
  return;
}


void dungeon::print_dung()
{
  string map = "";
  string hor_border(m_len, '-');
  map +=  "+" + hor_border + "+\n";

  for(int row = 0; row < m_hgt; row++)
  {
    map += "|";
    for(int clm = 0; clm < m_len; clm++)
      map += map_coords[row][clm];
    map += "|\n";
  }

  map +=  "+" + hor_border + "+";
  cout << map << endl;
  return;
}

void dungeon::print_dung_data()
{
  cout << "Outputing Dungeon Data...." << endl;
  for(int i = 0; i < m_num_rooms; i++)
  {
    cout << "  Room #" << i+1 << ":" << endl;
    cout << "    Length:     " << m_rooms[i].m_length << endl;
    cout << "    Heigth:     " << m_rooms[i].m_height << endl; 
    cout << "    Low Left X: " << m_rooms[i].m_cnr.m_low_l.x << endl;
    cout << "    Low Left Y: " << m_rooms[i].m_cnr.m_low_l.y << endl;
  }
}
