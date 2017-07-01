#include "opencv2/opencv.hpp"
#include <openpose/core/headers.hpp>
#include <openpose/filestream/headers.hpp>
#include <openpose/gui/headers.hpp>
#include <openpose/pose/headers.hpp>
#include <openpose/utilities/headers.hpp>


int main(){
	cv::VideoCapture cap("/home/guanyue/IVA/@Data_Center_S06 - 2053P Gate F57 F58 - 20170616 070000.mp4");	

	op::Point<int> outputSize;
	outputSize.x = 1280;
	outputSize.y = 720;
	op::Point<int> netInputSize;
	netInputSize.x = 656;
	netInputSize.y = 368;
	op::Point<int> netOutputSize = netInputSize;
	op::PoseModel poseModel = op::PoseModel::COCO_18;

	op::CvMatToOpInput cvMatToOpInput{netInputSize, 1, 0.3f};
	op::CvMatToOpOutput cvMatToOpOutput{outputSize};
	op::PoseExtractorCaffe poseExtractorCaffe{netInputSize, netOutputSize, outputSize, 1, poseModel, "../../../models/", 0};

	op::PoseRenderer poseRenderer{netOutputSize, outputSize, poseModel, nullptr, true, 0.6f};
	op::OpOutputToCvMat opOutputToCvMat{outputSize};
	const op::Point<int> windowedSize = outputSize;
	poseExtractorCaffe.initializationOnThread();
	poseRenderer.initializationOnThread();

	while(1){
		cv::Mat f;
		cap >> f;
		if(f.empty()) break;

		op::Array<float> netInputArray;
		std::vector<float> scaleRatios;
		std::tie(netInputArray, scaleRatios) = cvMatToOpInput.format(f);

		double scaleInputToOutput;
		op::Array<float> outputArray;
		std::tie(scaleInputToOutput, outputArray) = cvMatToOpOutput.format(f);
	
		poseExtractorCaffe.forwardPass(netInputArray, {f.cols, f.rows}, scaleRatios);
		const auto poseKeypoints = poseExtractorCaffe.getPoseKeypoints();

		poseRenderer.renderPose(outputArray, poseKeypoints);
		auto outputImage = opOutputToCvMat.formatToCvMat(outputArray);

		cv::imshow("a",outputImage);
		cv::waitKey(0);
	}
	return 0;
}
