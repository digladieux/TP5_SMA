#include "../header/State.hpp"

State::State() {}

State::~State() {}

void State::run(Grid &, Character *) {}
void State::run(Ground *, Character *) {}
void State::run(Character *) {}