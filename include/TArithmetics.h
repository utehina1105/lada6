#pragma once
#include "TStack.h"
#include <string.h>

int Prior(char c) {
	if ((c == '*') || (c == '/'))
		return 3;
	else if ((c == '+') || (c == '-'))
		return 2;
	else if (c == '(')
		return 1;
	else
		throw "error";
}

char* Stroka(char* s) {
	TStack<char> l;
	int count = strlen(s);
	char* s2 = new char[count + 1] {'\0'};
	int g = 0;
	for (int i = 0; i < count; i++) {
		if (isdigit(s[i])) {
			s2[g] = s[i];
			g++;
		}
		else if (s[i] == ')') {
			char m = l.pull();
			while (m != '(') {
				s2[g] = m;
				g++;
				m = l.pull();
			}
		}
		else {
			int p = Prior(s[i]);
			if (l.isEmpty() == true) {
				l.push(s[i]);
			} else {
				char n = l.pull();
				int pn = Prior(n);
				if (pn < p) {
					l.push(n);
					l.push(s[i]);
				} else {
					while ((pn >= p) && (!l.isEmpty())) {
						s2[g] = n;
						g++;
						n = l.pull();
						pn = Prior(n);
					}
					l.push(n);
					l.push(s[i]);
				}
			}
		}
	}
	while (!l.isEmpty()) {
		s2[g] = l.pull();
		g++;
	}
	return s2;
}

double Calculat(char* s) {
  TStack<double> number;
  TStack<char> operate;
  for (int i = 0; i < strlen(s); i++) {
    char curr = s[i];
    if (isdigit(curr))
      number.push(curr - '0');
    else if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
      operate.push(curr);
    else if (curr == '=')
    {
      while (!(operate.isEmpty()))
      {
        char operation = operate.top();
        operate.pull();
        double num2 = number.top();
        number.pull();
        double num1 = number.top();
        number.pull();

        if (operation == '+')
          number.push(num1 + num2);
        else if (operation == '-')
          number.push(num1 - num2);
        else if (operation == '*')
          number.push(num1 * num2);
        else if (operation == '/')
          number.push(num1 / num2);
      }
    }
  }
  return number.top();
}