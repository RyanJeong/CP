/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string Base64Encode(uint8_t const *buf, unsigned int buf_len);
std::vector<uint8_t> Base64Decode(std::string const& encoded_string);

static const char *kBase64Characters =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

static inline bool IsBase64(uint8_t c) {
  return std::isalnum(c) || c == '+' || c == '/';
}

std::string Base64Encode(uint8_t const *buf, unsigned int buf_len) {
  static uint8_t char_array_3[3], char_array_4[4];
  static int i, j;
  std::string ret;

  i = 0;
  while (buf_len--) {
    char_array_3[i++] = *(buf++);
    if (i == 3) {
      char_array_4[0] =
          (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] =
          ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] =
          ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] =
          char_array_3[2] & 0x3f;

      for (i = 0; i < 4; ++i)
        ret += kBase64Characters[char_array_4[i]];
      i = 0;
    }
  }

  j = 0;
  if (i) {
    for (j = i; j < 3; ++j)
      char_array_3[j] = '\0';

    char_array_4[0] =
        (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] =
        ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] =
        ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] =
        char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); ++j)
      ret += kBase64Characters[char_array_4[j]];

    while (i++ < 3)
      ret += '=';
  }

  return ret;
}

std::vector<uint8_t> Base64Decode(std::string const& encoded_string) {
  static const std::string kBase64Chars(kBase64Characters);
  static uint8_t char_array_4[4], char_array_3[3];
  static int i, j;
  int in_len = encoded_string.size();
  int in = 0;
  std::vector<uint8_t> ret;

  i = 0;
  while (in_len-- &&
         encoded_string[in] != '=' &&
         IsBase64(encoded_string[in])) {
    char_array_4[i++] = encoded_string[in++];
    if (i == 4) {
      for (i = 0; i < 4; ++i)
        char_array_4[i] = kBase64Chars.find(char_array_4[i]);

      char_array_3[0] =
          (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] =
          ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] =
          ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); ++i)
        ret.push_back(char_array_3[i]);
      i = 0;
    }
  }

  j = 0;
  if (i) {
    for (j = i; j < 4; ++j)
      char_array_4[j] = 0;

    for (j = 0; j < 4; ++j)
      char_array_4[j] = kBase64Chars.find(char_array_4[j]);

    char_array_3[0] =
        (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] =
        ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] =
        ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; j < i - 1; ++j)
      ret.push_back(char_array_3[j]);
  }

  return ret;
}

int main() {
  std::string str;
  std::cin >> str;

  // // encode
  // std::vector<uint8_t> buffer{str.data(), str.data() + str.size()};
  // std::string encoded_data = Base64Encode(&buffer[0], buffer.size());
  // std::cout << encoded_data << '\n';

  // decode
  // std::vector<uint8_t> decoded_data = Base64Decode(encoded_data);
  // std::string result{decoded_data.data(),
  //                    decoded_data.data() + decoded_data.size()};
  // std::cout << result << '\n';
  std::vector<uint8_t> decoded_data = Base64Decode(str);
  std::string result{decoded_data.data(),
                     decoded_data.data() + decoded_data.size()};


  return 0;
}
