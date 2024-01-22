#include <iostream>

using namespace std;

class Printer {
public:
    /**
     * Outputs a string to the printer and moves to the next line.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are left blank.
     *              The string is truncated to the line width.
     */
    virtual void println(std::string line) = 0;

    /**
     * A debug version of {@link #println(String)} which outputs any unsupported character by overprinting '0' and '1'.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are rendered by overprinting '0' and '1'.
     *              The string is truncated to the line width.
     */
    virtual void dprintln(std::string line) = 0;

    /**
     * Prints a string using proportional-spacing.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are left blank.
     *              The string is truncated to the line width.
     */
    virtual void pprintln(std::string line) = 0;
};