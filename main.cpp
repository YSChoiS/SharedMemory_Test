#include <iostream>
#include <chrono>
#include "YSsharedMemory.hpp"
#include "HSSharedMemory.hpp"
#include "OriSharedMemory.hpp"
#include <memory>


pSHMYS YSsharedMemory = new _SHM_(1,1);
pSHMORI ORIsharedMemory;
std::shared_ptr<SH_DATA> SharedData = std::make_shared<SH_DATA>();

void initHSSharedData(){
    SharedData->GlobalBaseAngularVelocity.setZero();
    SharedData->GlobalBaseEulerAngle.setZero();
    SharedData->GlobalBaseQuaternion.setZero();
    SharedData->localTime = 0;
}

void clearORISharedMemory(){
    ORIsharedMemory->localTime = 0;
    ORIsharedMemory->estimatedGroundSlope.setZero();
}

int main() {
    ORIsharedMemory = (pSHMORI)malloc(sizeof(SHMORI));
    clearORISharedMemory();
    initHSSharedData();

    const long long numIterations = 1000000000; // 반복 횟수 10억
    volatile int result_0 = 0;
    volatile int result = 0; // 'volatile'은 컴파일러 최적화를 방지합니다.
    volatile int result2 = 0;
    volatile int result3 = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < numIterations; ++i){
        result_0 += i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "No sharedMemory Access Time:  " << elapsed.count() << " ms\n";

    //YS
    start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < numIterations; ++i){
        YSsharedMemory->timeVariable.updateCurrentTime(i);
        result += YSsharedMemory->timeVariable.getCurrentTime(); // 결과를 누적하여 사용
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Yeongsu sharedMemory Access Time:  " << elapsed.count() << " ms\n";


    //ORI
    start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < numIterations; ++i){
        ORIsharedMemory->localTime = i;
        result2 += ORIsharedMemory->localTime; // 결과를 누적하여 사용
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Canine sharedMemory Access Time:  " << elapsed.count() << " ms\n";

    //HS
    start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < numIterations; ++i) {
        SharedData->localTime = i;
        result3 += SharedData->localTime; // 결과를 누적하여 사용
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Hosun sharedMemory Access Time: " << elapsed.count() << " ms\n";


    // 'result'를 출력하거나 사용하여 최적화에 의한 제거 방지
    std::cout << "Final result (to prevent optimization): " << result_0 << std::endl;
    std::cout << "Final result (to prevent optimization): " << result << std::endl;
    std::cout << "Final result (to prevent optimization): " << result2 << std::endl;
    std::cout << "Final result (to prevent optimization): " << result3 << std::endl;

    return 0;
}
