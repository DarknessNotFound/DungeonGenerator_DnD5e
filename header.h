//Programmer: DarknessNotFound
//File:       header.h
//Date:       3/1/2021
//Purpose:    The header to combine all the other headers and any miscellaneous
//	      functions.

#ifndef DUNG_GEN_MAIN_HEADER_H
#define DUNG_GEN_MAIN_HEADER_H


const short SQ_TO_FEET = 5; //Conversion rate between squares and feet

struct room
{ 
  short m_length;
  short m_width;
  short m_num_exits;
  short m_start_x;//Lower left corner
  short m_start_y; 
};

class dungeon
{
  private:
    short m_len = 100;//In squares
    short m_wid = 100;//In squares
    short m_area = m_len * m_wid;
    static const short m_num_rooms = 5;//Will eventually be -1 for "not initialized"
    short m_num_encounters = 3;//Will eventually be -1 for "not initialized"
    room m_rooms[m_num_rooms];
  public:
    room generate_room(const short room_id);
    void generate();
    void print_dung();
    void print_dung_data();
};

void generate_dungeon(dungeon &dung);
#endif
