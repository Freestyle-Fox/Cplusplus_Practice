#include <iostream>
#include <string>
#include <Windows.h>
#include "google/cloud/speech/v1/cloud_speech.grpc.pb.h" // Import  Cloud SpeGoogleech API

using google::cloud::speech::v1::Speech;
using google::cloud::speech::v1::RecognitionAudio;
using google::cloud::speech::v1::RecognitionConfig;
using google::cloud::speech::v1::RecognizeRequest;
using google::cloud::speech::v1::RecognizeResponse;

int main() {
    // Initialize the speech recognition API client
    // Replace "YOUR_API_KEY" with your actual API key
    std::string api_key = "YOUR_API_KEY";
    std::shared_ptr<grpc::ChannelCredentials> creds = grpc::SslCredentials(grpc::SslCredentialsOptions());
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("speech.googleapis.com", creds);
    std::unique_ptr<Speech::Stub> stub = Speech::NewStub(channel);

    // Set up the recognition configuration
    RecognitionConfig config;
    config.set_encoding(RecognitionConfig::FLAC); // Use FLAC audio format
    config.set_sample_rate_hertz(44100); // Use a sample rate of 44100 Hz
    config.set_language_code("en-US"); // Set the language code to US English

    // Start listening for voice commands
    std::cout << "Speak now to play a song...\n";
    while (true) {
        // Record audio input from the user
        // Replace "audio.flac" with the name of your audio file
        std::system("rec -r 44100 -c 2 -b 16 audio.flac trim 0 5"); // Record for 5 seconds
        std::ifstream audio_file("audio.flac", std::ios::binary);
        std::string audio_data((std::istreambuf_iterator<char>(audio_file)), std::istreambuf_iterator<char>());
        audio_file.close();

        // Send the audio data to the speech recognition API
        RecognizeRequest request;
        request.mutable_config()->CopyFrom(config);
        request.mutable_audio()->set_content(audio_data);
        grpc::ClientContext context;
        RecognizeResponse response;
        grpc::Status status = stub->Recognize(&context, request, &response);
        if (!status.ok()) {
            std::cerr << "Error: " << status.error_code() << " - " << status.error_message() << std::endl;
            break;
        }

        // Extract the text transcription from the API response
        std::string transcript;
        for (const auto& result : response.results()) {
            for (const auto& alternative : result.alternatives()) {
                transcript += alternative.transcript();
            }
        }

        // Play the desired song based on the user's voice command
        if (transcript == "play song one") {
            // Replace "song1.mp3" with the name of your song file
            std::system("start song1.mp3");
        } else if (transcript == "play song two") {
            // Replace "song2.mp3" with the name of your song file
            std::system("start song2.mp3");
        } else if (transcript == "stop
