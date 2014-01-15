/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  Gestione immagini pnm
  pnm_utils.cpp
#####################################*/

#include <fstream>

/** Write a PPM file
 * @param filename a file 
 * @param buf an RGB buffer
 * @param width geometry of buffer
 * @param height geometry of buffer
 * @return true if file is created
 */
bool write_ppm(const char *filename, const unsigned char *buf, unsigned int width, unsigned int height)
{
std::ofstream out(filename, std::ios::out | std::ios::binary);
if(out)
  {
  out << "P6\n" << width << ' ' << height << "\n255\n";
  out.write(reinterpret_cast<const char *>(buf), width*height*3);
  return true;
  }
else
 return false;
}

/** Write a PGM file
 * @param filename a file 
 * @param buf an greyscale buffer
 * @param width geometry of buffer
 * @param height geometry of buffer
 * @return true if file is created
 */
bool write_pgm(const char *filename, const unsigned char *buf, unsigned int width, unsigned int height)
{
std::ofstream out(filename, std::ios::out | std::ios::binary);
if(out)
  {
  out << "P5\n" << width << ' ' << height << "\n255\n";
  out.write(reinterpret_cast<const char *>(buf), width*height);
  return true;
  }
else
 return false;
}



static void pnm_skip_comments(std::istream & i)
{
 while (isspace(i.peek()))
    {
    while (isspace(i.peek()))
        i.get();
    if (i.peek() == '#')
      while (i.peek()!='\r' && i.peek()!='\n')
           { i.get(); }
       }
}

static char pnm_read_header(unsigned int & width, unsigned int &height, std::istream &iss)
{
  char h, t; 
  int max_val;

  // check pnm header
  h = iss.get();
  t = iss.get();
  if(!((h=='P') && ((t=='5')||(t=='6'))))
    return '\0';

  pnm_skip_comments(iss);
  iss>>width;
  pnm_skip_comments(iss);
  iss>>height;
  pnm_skip_comments(iss);
  iss>>max_val;
  iss.get(); // TODO: use a getline fn 
  return t;
}

/// Load a PGM image, reserve memory with new and return geometry
/// @param [out] width|height geometry of image
/// @param [in] file filename
/// @return a pointer to image first pixel allocated with new operator, or NULL in case of error
unsigned char *pgm_load(unsigned int & width, unsigned int &height, const char *file)
{
  std::ifstream istr(file);
  if(pnm_read_header(width,height,istr)!='5')
    return NULL;
  // buffer size
  unsigned char *buffer = new unsigned char [width * height];

  istr.read(reinterpret_cast<char *>(buffer),  width * height);

  return buffer;
}

/// Load a PPM image, reserve memory with new and return geometry
/// @param [out] width|height geometry of image
/// @param [in] file filename
/// @return a pointer to image first pixel allocated with new operator, or NULL in case of error
unsigned char *ppm_load(unsigned int & width, unsigned int &height, const char *file)
{
  std::ifstream istr(file);
  if(pnm_read_header(width,height,istr)!='6')
    return NULL;
  // buffer size
  unsigned char *buffer = new unsigned char [width * height*3];

  istr.read(reinterpret_cast<char *>(buffer),  width * height*3);

  return buffer;
}





/*   
*   writepnm.cpp Copyright (C) 2008-2010 Paolo Medici
*
*   This library is free software; you can redistribute it and/or modify it under the terms of the 
*    GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of 
*    the License, or (at your option) any later version.
*
*   This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
*    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public 
*    License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License along with this library; if not, 
*   write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
*/
