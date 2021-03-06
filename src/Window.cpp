#include "Window.hpp"

Window::Window(int y, int x, int start_y, int start_x, const std::string &title) {
    win = newwin(y, x, start_y, start_x);
    this->title = title;
    rows = y;
    cols = x;
    draw_borders();
    scrollok(win, TRUE);
    idlok(win, TRUE);
};

Window::~Window() {
    delwin(win);
}

void Window::draw_borders() {
    wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 0, "%.*s", cols, title.c_str());
    wattroff(win, A_BOLD);
    wrefresh(win);
}

int Window::get_real_rows() {
    return rows - 2;
}

int Window::get_real_cols() {
    return cols - 2;
}

