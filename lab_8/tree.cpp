#include "tree.h"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

//-----------------------------------------------------------------------------
// Функция для запуска задачи с деревом
//-----------------------------------------------------------------------------
void run_tree_task() {
    TreeNode root(1);
    auto left_son = root.AddChild(10);
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);
    left_son->AddChild(100);
    left_son->AddChild(200);
    root.Print();
}
