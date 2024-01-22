package com.kardium.exams.printer;

/*
 * Copyright Kardium Inc. 2023.
 */

/**
 * Fill out this class to implement the {@link Printer} interface.
 */
public class ChainPrinter implements Printer {
    private final ChainPrinterDriver driver;

    public ChainPrinter(ChainPrinterDriver driver) {
        this.driver = driver;
    }

    @Override
    public void println(String line) {
        // REPLACE THIS WITH YOUR CODE
        driver.fire(0);
        driver.step();
        driver.linefeed();
    }

    @Override
    public void dprintln(String line) {
        // REPLACE THIS WITH YOUR CODE
        println(line);
    }

    @Override
    public void pprintln(String line) {
        // REPLACE THIS WITH YOUR CODE
        println(line);
    }
}
