package com.kardium.exams.printer;

/*
 * Copyright Kardium Inc. 2023.
 */

/**
 * Hypothetical printer interface.
 */
public interface Printer {

    /**
     * Outputs a string to the printer and moves to the next line.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are left blank.
     *              The string is truncated to the line width.
     */
    void println(String line);

    /**
     * A debug version of {@link #println(String)} which outputs any unsupported character by overprinting '0' and '1'.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are rendered by overprinting '0' and '1'.
     *              The string is truncated to the line width.
     */
    void dprintln(String line);

    /**
     * Prints a string using proportional-spacing.
     *
     * @param line  A string containing '0', '1' and ' ' characters.
     *              Other characters are left blank.
     *              The string is truncated to the line width.
     */
    void pprintln(String line);
}
