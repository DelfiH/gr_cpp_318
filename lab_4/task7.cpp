#include "tasks.h"
#include <iostream>
#include <string>
#include <algorithm>

// Type alias ��� ���襭�� �⠥����
using phase_string = std::string;

// ������� 7: ����⠭���� ��ப�
void task7() {
    phase_string phases = "UVWN";
    std::cout << "��ਠ��� ������祭�� ����⮪ ��� 3�-䠧���� �����⥫� UVWN:\n";
    std::size_t count = 0;
    std::sort(phases.begin(), phases.end());
    do {
        std::cout << phases << std::endl;
        count++;
    } while (std::next_permutation(phases.begin(), phases.end()));
    std::cout << "�ᥣ� ����⠭����: " << count << std::endl;
}
