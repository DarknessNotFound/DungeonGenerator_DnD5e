//Programmer: DarknessNotFound
//File:       header.h
//Date:       3/1/2021
//Purpose:    The header to combine all the other headers and any miscellaneous
//	      functions.

#ifndef DUNG_GEN_MAIN_HEADER_H
#define DUNG_GEN_MAIN_HEADER_H


const short SQ_TO_FEET = 5; //Conversion rate between squares and feet
struct point
{
  short x;
  short y;
};

struct corners
{
  point m_low_l;
  point m_low_r;
  point m_upp_l;
  point m_upp_r;
};

struct room
{ 
  short m_length;
  short m_height;
  short m_num_exits;
  corners m_cnr;
};

class dungeon
{
  private:
    static const short m_len = 100;//In squares
    static const short m_hgt = 100;//In squares
    short m_area = m_len * m_hgt;
    static const short m_num_rooms = 5;//Will eventually be -1 for "not initialized"
    short m_num_encounters = 3;//Will eventually be -1 for "not initialized"
    room m_rooms[m_num_rooms];
    bool crn_on_row_exists(const int row);
    char map_coords[m_hgt][m_len]= {""};//in {row, colm}
    void initilize_map();
  public:
    room generate_room(const short room_id);
    void generate();
    void print_dung();
    void print_dung_data();
};

void generate_dungeon(dungeon &dung);
#endif
