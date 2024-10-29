#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// 存储每块钢板的信息，每个元素是一个包含起始位置、结束位置和钢板编号的三元数组
vector<vector<int>> steelPlates;

// 比较函数：按钢板的起始位置升序排序
bool compareByStartPosition(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

// 自定义比较器，用于排序 set 中的钢板
// 按钢板的结束位置降序排序，如果结束位置相同，则按钢板编号升序
struct SteelPlateComparator {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return (a[1] == b[1]) ? a[2] < b[2] : a[1] > b[1];
    }
};

vector<int> removedSteelPlates; // 存储被移除钢板的编号

int main() {
    int numSteelPlates, maxWeight;
    cin >> numSteelPlates >> maxWeight;

    // 初始化 steelPlates 数组，存储每块钢板的信息
    steelPlates.resize(numSteelPlates, vector<int>(3));
    for (int i = 0; i < numSteelPlates; i++) {
        cin >> steelPlates[i][0] >> steelPlates[i][1]; // 输入钢板的起始和结束位置
        steelPlates[i][2] = i + 1; // 钢板编号
    }

    // 按钢板的起始位置升序排序
    sort(steelPlates.begin(), steelPlates.end(), compareByStartPosition);

    // 定义 set，使用自定义比较器，以按结束位置降序维护钢板
    set<vector<int>, SteelPlateComparator> activeSteelPlates;

    int currentSteelPlate = 0;

    // 遍历机器人位置，从 1 到最大可能的钢板结束位置
    for (int robotPosition = 1; robotPosition <= 200; robotPosition++) {
        // 将起始位置小于等于当前机器人位置的钢板加入 activeSteelPlates
        while (currentSteelPlate < numSteelPlates && steelPlates[currentSteelPlate][0] <= robotPosition) {
            activeSteelPlates.insert(steelPlates[currentSteelPlate]);
            currentSteelPlate++;
        }

        // 移除结束位置小于当前机器人位置的过期钢板
        while (!activeSteelPlates.empty()) {
            vector<int> latestSteelPlate = *(--activeSteelPlates.end());
            if (latestSteelPlate[1] < robotPosition) {
                activeSteelPlates.erase(latestSteelPlate);
            } else {
                break;
            }
        }

        // 如果当前活跃钢板数超过允许的最大重量 maxWeight，则移除最早的钢板
        while (activeSteelPlates.size() > maxWeight) {
            vector<int> earliestSteelPlate = *activeSteelPlates.begin();
            removedSteelPlates.push_back(earliestSteelPlate[2]); // 记录被移除钢板的编号
            activeSteelPlates.erase(activeSteelPlates.begin());
        }
    }

    // 输出被移除钢板的总数和编号
    cout << removedSteelPlates.size() << endl;
    for (int i = 0; i < removedSteelPlates.size(); i++) {
        cout << removedSteelPlates[i] << " ";
    }

    return 0;
}