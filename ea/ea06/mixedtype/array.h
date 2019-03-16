#ifndef ARREAY_H
#define ARRAY_H

#include <vector>
#include <string>
#include "item.h"

std::vector<Item*> upload(const std::string &fname);
void write(const std::vector<Item*> &x);

#endif // ARREAY_H
