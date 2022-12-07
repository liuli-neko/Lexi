#include <iostream>

#include "core/glyph/character.hpp"

using namespace lexi::common;
using namespace lexi::core;

int main(int argc, char **argv) {
  Character *character[30];
  Character *glyph = Character::New();

  for (int i = 0; i < 26; ++i) {
    character[i] = Character::New();
    character[i]->SetValue('a' + i);
  }

  character[26] = Character::New();
  character[26]->SetValue(U'你');

  character[27] = Character::New();
  character[27]->SetValue(U'☹');

  character[28] = Character::New();
  character[28]->SetValue(U'ξ');

  character[29] = Character::New();
  character[29]->SetValue(U'ぬ');

  glyph->SetValue('@');
  for (int i = 0; i < 30; ++i) {
    glyph->Insert(character[i], i);
  }

  for (int i = 0; i < 30; i++) {
    std::cout << glyph->Child(i)->ToCharacter() << " ";
  }

  std::cout << std::endl;

  auto it = glyph->Begin();
  for (; it != glyph->End(); ++it) {
    std::cout << it->ToCharacter() << " ";
  }
  std::cout << std::endl;

  it = glyph->Begin();
  for (; !it.IsDone(); it++) {
    std::cout << it->ToCharacter() << " ";
  }
  std::cout << std::endl;

  delete glyph;

  return 0;
}
