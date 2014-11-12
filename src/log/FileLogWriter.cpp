/* The MIT License (MIT)
*
* Copyright (c) 2014 Michael Crawford
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "log/FileLogWriter.h"

namespace util
{

FileLogWriter::FileLogWriter(const std::string& filename, bool append)
  : FileLogWriter()
{
  open(filename, append);
}

bool FileLogWriter::open(const std::string& filename, bool append)
{
  close();

  assert(!filename.empty());
  auto mode = std::ios::out |
    (append ? std::ios::app : std::ios::trunc);
  file.open(filename.c_str(), mode);
  return file.is_open();
}

void FileLogWriter::close()
{
  if (file.is_open())
  {
    file.close();
  }
}

bool FileLogWriter::isOpen() const
{
  return file.is_open();
}

void FileLogWriter::output(const std::string& msg)
{
  assert(file.is_open());
  file << msg << std::endl;
}

}
