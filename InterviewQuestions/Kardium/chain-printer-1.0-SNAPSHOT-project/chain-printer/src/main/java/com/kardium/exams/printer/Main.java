package com.kardium.exams.printer;

/*
 * Copyright Kardium Inc. 2023.
 */

public class Main {
    public static void main(String[] args) {
        Printer printer = new ChainPrinter(new LoggingChainPrinterDriver());
        printer.println("00000000");
        printer.dprintln("01234567");
        printer.pprintln("01100101");
    }
}
