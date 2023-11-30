#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////
//
//  QUESTION 1
//
//
// Q1: Figure 1 below shows an example of a typical position peak signal (blue) from which we derive the
// peak position for a single point. Figure 2 shows a commonly occurring problem with the current
// generation scanner, where the position peak signal has two peaks instead of the expected singular peak
// characteristic of a gaussian distribution. How would you find the index, from 0 to 2047, along the pixel
// array (black rectangles), where the peak is to a resolution greater than a single pixel position? i.e. peak is
// at pixel 1024.213. If possible, include handling for the abnormal peak signal.

// Write a function in C++ to accomplish the task above. You may assume that the input argument is the
// peak signal data, stored in a std::vector<int>. The return should the peak position as a double.
////////////////////////////////////////////////////////////////////////

/**
 * @brief Encodes the peak data into a double.
 *
 * This function encodes the number of peaks and their indexes into a double.
 * The format of the encoded data is A.xxxx_yyyy_zzzz, where A is the number of peaks,
 * and xxxx, yyyy, zzzz are the indexes of the largest, second largest, and third largest peaks respectively.
 * Each index is represented in four decimal places in the fractional part of the double.
 *
 * @param peakIndexes A vector of integers representing the indexes of the peaks.
 * @return double The encoded peak data.
 * @note The function assumes that the peak indexes have a maximum value of 2047
 */
double encodePeakData(const std::vector<int>& peakIndexes) {
    double encoded = peakIndexes.size(); // Number of peaks as the integer part

    // Encoding each peak index in 4 decimal places
    double placeValue = 0.0001; // Start with the first 4 decimal places
    for (int index : peakIndexes) {
        encoded += index * placeValue;
        placeValue *= 0.0001; // Move to the next 4 decimal places
    }

    return encoded;
}

/**
 * @brief Decodes the peak data from an encoded double.
 *
 * This function decodes the peak data encoded in the format A.xxxx_yyyy_zzzz,
 * where A is the number of peaks, and xxxx, yyyy, zzzz are the indexes of the peaks.
 * The function extracts the integer part for the number of peaks and then sequentially
 * extracts each set of four decimal places for the peak indexes.
 *
 * @param encoded The encoded double value containing the peak data.
 * @return std::vector<int> A vector of integers representing the decoded peak indexes.
 */
std::vector<int> decodePeakData(double encoded) {
    std::vector<int> peakIndexes;

    // Extract the number of peaks from the integer part
    int numPeaks = static_cast<int>(encoded);

    // Extract each peak index from the fractional part
    double fractionalPart = encoded - numPeaks;
    double placeValue = 0.0001;

    for (int i = 0; i < numPeaks; ++i) {
        int index = static_cast<int>(round(fractionalPart / placeValue));
        peakIndexes.push_back(index);
        fractionalPart -= index * placeValue;
        placeValue *= 0.0001;
    }

    return peakIndexes;
}

/**
 * @brief Finds and encodes the positions of the largest peaks in a signal.
 *
 * This function processes a given signal to identify the positions of the largest peaks.
 * It then encodes these positions into a double using a specific format. The format used for encoding
 * is A.xxxx_yyyy_zzzz, where A is the number of peaks, and xxxx, yyyy, zzzz are the indexes
 * of the largest, second largest, and third largest peaks respectively. Each index is normalized
 * and represented in four decimal places in the fractional part of the double.
 * 
 * If there is no peak, it will return -1
 *
 * @param signal A std::vector<int> representing the signal data.
 * @return double The encoded value representing the peak positions. The number of peaks is
 *         represented by the integer part, and their positions are encoded in the fractional part.
 *
 * @note The function assumes that the signal contains discrete values and that the peak positions
 *       can be accurately represented within the precision limits of a double.
 * @note The function is designed to handle up to three peaks. If there are more than three peaks
 *       in the signal, only the positions of the three largest peaks are encoded.
 *      
 *       With this encoding format, we can reliably respond with 2.8 peaks
 *       But Since the data is normally distributed, we can try to squeeze in a third peak. Therefore,
 *       The third peak index could be truncated
 */
double findPeakPosition(const std::vector<int>& signal) {
    std::vector<std::pair<int, int>> peaks; // Pair of peak value and index

    //if no size
    if(signal.size() == 0){ return -1;}

    //The peak has a special condition where both elements to the right and left will be lower than it
    for (int i = 1; i < signal.size() - 1; ++i) {
        if (signal[i] > signal[i - 1] && signal[i] > signal[i + 1]) { //Check if it is a peak
            peaks.emplace_back(signal[i], i);
        }
    }

    //check if the peak is at an edge
    if(signal[0] > signal[1]){
        peaks.emplace_back(signal[0], 0);
    } else if(signal[signal.size() -1 ] > signal[signal.size() - 2]){
        peaks.emplace_back(signal[signal.size() -1], (signal.size() -1));
    }

    //if no peaks, return -1
    if(peaks.size() == 0){ 
             return -1; //no peaks
    }

    // Sort peaks based on their values
    std::sort(peaks.begin(), peaks.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });


    // Extract indexes of the largest peaks
    std::vector<int> peakIndexes;
    for (const auto& peak : peaks) {
        peakIndexes.push_back(peak.second);
        if (peakIndexes.size() == 3) break; // Limit to top 3 largest peaks
    }


    //Return the peaks average as a double
    return encodePeakData(peakIndexes);
    
}

int main() {
    std::vector<int> signal = {10, 20, 50, 1024, 50, 20, 10}; //Expect 3 as the indexes
    std::vector<int> signal2 = {10, 20, 1024, 30, 10, 500, 20, 10}; //Expect 2 and 5 as the indexes
    std::vector<int> signal3 = {10, 1024, 30, 10, 500, 20, 800, 10}; //Expect 1, 6 and 4 as the indexes
    std::vector<int> signal4 = {}; //Expect -1, no peaks
    std::vector<int> signal5 = {1024, 30, 10, 500, 20, 800, 10}; //Expect 0, 6 and 4 as the indexes
    std::vector<int> signal6 = {30, 30, 30}; //Expect -1, no peaks

    double encodedPeaks = findPeakPosition(signal3);
    std::cout << "Encoded Peak Data: " << encodedPeaks << std::endl;

    if(encodedPeaks == -1){
        return 0;
    }

    std::vector<int> decodedPeaks = decodePeakData(encodedPeaks);
    std::cout << "Decoded Peak Indexes: ";
    for (int index : decodedPeaks) {
        std::cout << index << " ";
    }
    std::cout << std::endl;


    return 0;
}

/////////////////////////////////////////////////////////////////////////
//
//          QUESTION 2
//
//
// Q2: A program sends a stream of data packets to another program using an unspecified communication
// method. Assuming that the unspecified communication method does not check for data integrity, how
// would you ensure using software that the 2nd program accepting the data stream continues receiving
// valid packets?
// Describe your solution to the above problem using plain English. You may use brief pseudo code to help
// illustrate your answer.
////////////////////////////////////////////////////////////////////////

/* In sending function, I would use CRC64 (Detect errors ) or BCH code (Detect errors but can correct up to certain errors). CRC codes are easier and more common but would use BCH in this case

In receiving function, I would check for an error
    If there is an error, check and see if it is correctable
        if correctable, correct
        if not correctable, request a resend of data


// Sender side
function sendPacket(data):
    encodedData  = BCHencode(data)
    transmit(encodedData )

// Receiver side
function receivePacket(packet):
    decodedData, success = BCHdecode(encodedPacket)
    if success:
        process(decodedData)
        sendAcknowledgment()
    else:
        if errorIsCorrectable :
            correctErrors(decodedData)
            sendAcknowledgment()
        else :
            requestResend()

*/