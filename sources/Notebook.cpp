

#include <iostream>
#include "Notebook.hpp"
#include <map>
#include <string>
#include <string.h>
// using namespace ariel;
using ariel::Notebook;
const int max_col = max_col;

namespace ariel
{
    void Notebook::write(int page, int row, int col, ariel::Direction direction, std::string const &notebook_write)
    {
        error_write(page, row, col, direction, notebook_write);
        unsigned int sentence_length = (unsigned)notebook_write.length();
        unsigned int temp_col = (unsigned)col;
        unsigned int temp_row = (unsigned)row;
        int temp_index = 0;
        string temp_word = notebook_write;

        switch (direction)
        {
        case Direction::Horizontal:

            // for(unsigned int i =0 ; i<sentence_length ; i++)
            // {
            check_row(page, row, col, temp_word);
            // if(this->notebook[page][row][temp_col]!='_')
            if (!temp_word.empty())
            {
                std::string new_line = this->notebook[page][row].substr(0, temp_col) + notebook_write + this->notebook[page][row].substr(temp_col + sentence_length, (unsigned)max_col - (temp_col + sentence_length));

                this->notebook[page][row] = new_line;
            }
            else
            {
                throw invalid_argument("error       1");
            }

            // }
            break;

        case Direction::Vertical:

            // if (this->notebook[page][row][temp_col] != '_')
            // {
            //     throw invalid_argument("error          2");
            // }
            // else
            // {
            for (unsigned int i = 0; i < sentence_length; i++)
            {
                if (this->notebook[page][row][temp_col] != '_')
                {
                    throw invalid_argument("error          2");
                }
                this->notebook[page][row][temp_col] = notebook_write.at(i);
                row++;
            }

            // this->notebook[page][row] = new_line ;
            // }
            //  if(chack_input > max_col)
            // {
            //     throw invalid_argument(" your input will be out of bound        function write ");
            // }

            // for(unsigned int i =0 ; i<sentence_length ; i++)
            // {

            // if((notebook_write.at(i)=='_') || (notebook_write.at(i)== 0))
            // {
            //     this->notebook[page][row][col]=notebook_write.at(i);
            //     row++;

            // }else
            // {
            //     throw invalid_argument(" you trying to write in place the is already taken ");
            // }
            // }
            break;
        }
    }

    std::string Notebook::read(int page, int row, int col, ariel::Direction direction, int length)
    {
        unsigned int temp_col = (unsigned)col;
        unsigned int temp_row = (unsigned)row;
        unsigned int temp_len = (unsigned)length;

        int temp_index = 0;
        string word;
        error_read(page, row, col, direction, length);

        if (length == 0)
        {
            return "_";
        }
        switch (direction)
        {
        case Direction::Horizontal:
            // cout << " string are empty !!!!!!!!!!!!!!!!!!" << endl;

            if (this->notebook[page][row].empty())
            {
                string temp;
                init_row(temp);
                word = temp.substr(temp_col, temp_len);
                // throw invalid_argument("An empty string     1");
            }
            else
            {
                // cout << " the string are empty !!! .cpp  !!!" << endl;

                word += this->notebook[page][row].substr(temp_col, temp_len);
                if (word.empty())
                {
                    init_row(word, length);
                    if (word.empty())
                    {
                        throw invalid_argument(" read function !!!!   ");
                    }
                }
                // init_row(word , length);
                // for(unsigned int i=0 ; i<word.length() ; i++)
                // {
                //     if(word.at(i)==" ") //word[i]==" ")
                //     {
                //         word.at(i)='_';
                //     }
                //     // temp_col++;

                // }
            }

            break;

        case Direction::Vertical:

            for (int i = 0; i < length; i++)
            {
                if (this->notebook[page][row].empty())
                {
                    string temp;
                    init_row(temp);
                    this->notebook[page][row] += temp;
                    word += notebook[page][row][temp_col];
                }
                else
                {
                    word += notebook[page][row][temp_col];
                }

                row++;
            }
            break;
        }

        return word;
    }

    void Notebook::erase(int page, int row, int col, ariel::Direction direction, int length)
    {
        unsigned int temp_col = (unsigned)col;
        unsigned int temp_row = (unsigned)row;
        int temp_index = 0;

        error_erase(page, row, col, direction, length);
        switch (direction)
        {
        case Direction::Horizontal:
        
            if (length > max_col)
            {
                length = max_col;
            }
            cout<<"we start to eraes staff !!!!!!!!!!!!"<<endl;
            for (int i = 0; i < length; i++)
            {
                cout<<"we start to eraes staff !!!!!!!!!!!!"<<endl;
                 if ((this->notebook[page][row][temp_col] == '_') || (this->notebook[page][row][temp_col] == ' '))
                {
                    this->notebook[page][row][temp_col] = '~';
                }
                // else if (this->notebook[page][row][temp_col] == ' ')
                // {
                //     this->notebook[page][row][temp_col] = '~';
                // }
                else if (this->notebook[page][row][temp_col] == '~')
                {
                    continue;
                }
                else
                {
                    this->notebook[page][row][temp_col] = '~';
                }
                // if (this->notebook[page].empty())
                // {
                //     this->notebook[page] = map<int, std::string>();
                //     // this->notebook[page][row][temp_col] = '~';
                // }
                // if (this->notebook[page][row][temp_col] == '_')
                // {
                //     cout<<this->notebook[page][row]<<endl;
                //     // cout<<"erase function cpp !! "<<endl;
                //     this->notebook[page][row][temp_col] = '~';
                // }
                // if (this->notebook[page][row][temp_col] == ' ')
                // {
                //     this->notebook[page][row][temp_col] = '~';
                // }
                // if (this->notebook[page][row][temp_col] == '~')
                // {
                //     // continue ;
                //     this->notebook[page][row][temp_col] = '~';
                // }
                // // else
                // // {
                // // if(i<max_col)
                // // {
                // this->notebook[page][row][temp_col] = '~';
                // // }
                // // }
                temp_col++;
                
            }
            cout<<"we start to eraes staff !!!!!!!!!!!!"<<endl;
            cout<<"temp_col = "<< temp_col <<endl;
            break;

        case Direction::Vertical:
            for (int i = 0; i < length; i++)
            {
                if ((this->notebook[page][row][temp_col] == '_') || (this->notebook[page][row][temp_col] == ' '))
                {
                    this->notebook[page][row][temp_col] = '~';
                }
                // else if (this->notebook[page][row][temp_col] == ' ')
                // {
                //     this->notebook[page][row][temp_col] = '~';
                // }
                else if (this->notebook[page][row][temp_col] == '~')
                {
                    continue;
                }
                else
                {
                    this->notebook[page][row][temp_col] = '~';
                }
                row++;
            }
            break;
        }
    }

    void Notebook::show(int page)
    {
        if (page < 0)
        {
            throw invalid_argument("your input should be graeter then 0");
        }

        // if(page<0)
        // {
        //     throw invalid_argument("your input should be lase than 0     function show 1");
        // }
        // for (auto t : notebook) {
        //     cout << t.first << ":" ;
        //     for (auto t1 : t.second){
        //         cout << t.first << ":" << t1.first << " -> " << t1.second ;
        //         cout  << t1.second ;

        //     }
        //     cout << endl ;
        // }
    }

    Notebook ::Notebook(){

    };
    Notebook ::~Notebook(){

    };

}
