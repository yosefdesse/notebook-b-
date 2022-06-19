
#pragma once
#include <iostream>
#include "Direction.hpp"
#include <map>
#include <string>
#include <string.h>

using namespace std;
// typedef unsigned int uint;

namespace ariel
{
    class Notebook
    {
    private:
        void init_row(std::string &str)
        {
            for (int i = 0; i < 5; i++)
            {
                str += "____________________";
            }
        }

        void init_row(std::string &str, int length)
        {
            if (length < 100)
            {
                for (int i = 0; i < length; i++)
                {
                    str += "_";
                }
            }
        }

        void check_row(int page, int row, int col, std::string &str)
        {
            if (str.empty())
            {
                Notebook::init_row(str);
            }
        }

        void error_write(int page, int row, int col, ariel::Direction direction, std::string const &notebook_write)
        {
            int sentence_length = notebook_write.length();
            if (row < 0 || col < 0 || col >= 100 || page < 0)
            {
                throw invalid_argument("Incorrect parameters, can not write in negative locations");
            }
            if (notebook_write.empty())
            {
                throw invalid_argument("An empty string");
            }

            // Input deviation from the received column (no more than 100 columns)
            if ((sentence_length + col >= 100 || sentence_length >= 100) && direction == Direction::Horizontal)
            {
                throw invalid_argument("String length is invalid");
            }

            if (this->notebook[page].empty())
            {
                this->notebook[page] = map<int, std::string>();
                string temp;
                init_row(temp);
                notebook[page][row]=temp;
            }
            if (this->notebook[page][row].empty() && direction == Direction::Horizontal)
            {
                for (int i = 0; i < 5; i++)
                {
                    this->notebook[page][row] += "____________________";
                }
            }
            unsigned int temp_col = (unsigned)col;
            unsigned int temp_row = (unsigned)row;
            int temp_index;

            for (unsigned int i = 0; i < sentence_length && direction == Direction::Horizontal; i++)
            {
                if ((notebook_write[i] == '\n') || (notebook_write[i] < ' ') || (notebook_write[i] >= '~'))
                {
                    throw invalid_argument(" error");
                }
                if (this->notebook[page][row][temp_col + i] != '_')
                {
                    throw invalid_argument("error");
                }
            }
            for (unsigned int i = 0; i < sentence_length && direction == Direction::Vertical; i++)
            {
                temp_index = (int)i;
                if ((notebook_write[i] == '\n') || (notebook_write[i] < ' ') || (notebook_write[i] >= '~'))
                {
                    throw invalid_argument(" error    3");
                }
                if (this->notebook[page][row + temp_index].empty())
                {
                    std::string word;
                    for (int j = 0; j < 5; j++)
                    {
                        word += "____________________";
                    }
                    this->notebook[page][row + temp_index] = word;
                    continue;
                }
                //                 cout<< "row + temp_index = "<<row + temp_index<< "; temp_col = " <<temp_col<<endl;
                // cout<< "this->notebook[page][row + temp_index][temp_col] = " << this->notebook[page][row + temp_index][temp_col]<<endl;
                if (this->notebook[page][row + temp_index][temp_col] != '_')
                {
                    throw invalid_argument("error          4");
                }
            }
        }

        void error_read(int page, int row, int col, ariel::Direction direction, int length)
        {
            if (row < 0 || col < 0 || col >= 100 || page < 0)
            {
                throw invalid_argument("Incorrect parameters, can not write in negative locations");
            }
            if (length < 0) //|| length>=100 )
            {
                throw invalid_argument("your length input should be  less than 100 and greater than 0          1");
            }
            if (this->notebook[page].empty())
            {
                // throw invalid_argument("error      5");
                this->notebook[page] = map<int, std::string>();
            }
            if (this->notebook[page][row].empty())
            {
                string str;
                init_row(str);
                this->notebook[page][row] += str;
            }
            if ((length + col > 100 || length > 100) && direction == Direction::Horizontal)
            {
                throw invalid_argument("error              6");
            }
            if (direction == Direction::Vertical)
            {
                for (int i = 0; i < length; i++)
                {

                    if (this->notebook[page][row + i].empty())
                    {
                        string str;
                        init_row(str);
                        this->notebook[page][row + i] = str;
                    }
                }
            }
        }
        void error_erase(int page, int row, int col, ariel::Direction direction, int length)
        {
            if (row < 0 || col < 0 || col >= 100 || page < 0)
            {
                throw invalid_argument("your input should be greater than 0  and col should be less than 100 and greater than 0");
            }
            if (length < 0) //|| length>=100 )
            {
                throw invalid_argument("your length input should be  less than 100 and greater than 0       2");
            }
            if (this->notebook[page].empty())
            {
                // cout << "empty page function hpp !! " << endl;

                this->notebook[page] = map<int, std::string>();
                
            }
            if (length == 0)
            {
                throw invalid_argument("your trying to eraes an empty word");
            }
            // if (this->notebook[page][row].empty())
            // {
            //     throw invalid_argument("An empty string");

            // }
            if ((length + col >= 100 || length >= 100) && direction == Direction::Horizontal)
            {
                throw invalid_argument("error out of bound");
            }
            // for(int i=0 ; i<length && direction == Direction::Horizontal ; i++)
            // {

            // }

            int count = 0;
            for (int i = 0; i < length && direction == Direction::Vertical; i++)
            {

                if (this->notebook[page][row].empty())
                {
                    count++;
                    // throw invalid_argument("An empty string");
                }
            }
            if (count == length)
            {
                throw invalid_argument("An empty string");
            }
        }

    public:
        map<int, map<int, std::string>> notebook;

        // int max_row = 0;
        // int max_col = 0;
        // int min_row = 0;
        // int min_col = 0;

        // string s;
        Notebook();
        ~Notebook();
        void write(int page, int row, int col, ariel::Direction direction, std::string const &notebook_write);
        std::string read(int page, int row, int col, ariel::Direction direction, int length);
        void erase(int page, int row, int col, ariel::Direction direction, int length);
        void show(int page);
        // void init_row(int page ,int row  );
        // void check_row(int page ,int row , map< int , map< int , map<int , char>>> &noteBook);
    };

}