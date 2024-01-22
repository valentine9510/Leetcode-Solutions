package com.kardium.exams.printer;

/*
 * Copyright Kardium Inc. 2023.
 */

/**
 * Hypothetical chain printer driver interface.
 */
interface ChainPrinterDriver {

    /**
     * Fires the specified solenoid, returning immediately.
     *
     * @param solenoidIndex The solenoid index (0-7).
     */
    void fire(int solenoidIndex);

    /**
     * Waits for all solenoids to finish firing, then advances the chain one step (1 mm) to the left.
     * Returns after the chain has advanced.
     */
    void step();

    /**
     * Advances the paper feed by one line, returning after the paper has advanced.
     */
    void linefeed();
}
