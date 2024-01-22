package com.kardium.exams.printer;

/*
 * Copyright Kardium Inc. 2023.
 */

/**
 * Logs printer driver calls to standard output.
 */
public class LoggingChainPrinterDriver implements ChainPrinterDriver {
    @Override
    public void fire(int solenoidIndex) {
        System.out.println("Fire solenoid " + solenoidIndex);
    }

    @Override
    public void step() {
        System.out.println("Step chain 1 mm");
    }

    @Override
    public void linefeed() {
        System.out.println("Linefeed");
    }
}
