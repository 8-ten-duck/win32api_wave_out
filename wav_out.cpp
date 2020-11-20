#include"wav_out.hpp"

//ハンドルの設定関数
void set_wave_handle(
    WAVEFORMATEX& m_handle,
    const WORD format,
    const uint8_t ch,
    const uint32_t sampling_rate,
    const uint8_t sample_bit_depth,
    const size_t ex_size){
        //1バイトに必要なビット数
        const size_t nbit_of_byte = 8;
        //フォーマットが有効であることを保証する
        assert(format != WAVE_FORMAT_UNKNOWN);
        //サンプルのビット深度が有効であることを確かめる
        assert((sample_bit_depth % nbit_of_byte) == 0);
        //ハンドルに値をセットする
        m_handle.wFormatTag = format;
        m_handle.nChannels = ch;
        m_handle.nSamplesPerSec = sampling_rate;
        m_handle.wBitsPerSample = sample_bit_depth;
        m_handle.cbSize = ex_size;
        m_handle.nAvgBytesPerSec = sampling_rate * ch * sample_bit_depth / nbit_of_byte;
        m_handle.nBlockAlign = ch * sample_bit_depth / nbit_of_byte;
        //サンプルのビット深度が有効であることを確かめる
        assert((m_handle.wBitsPerSample % nbit_of_byte) == 0);
}

void release_wavehdr(HWAVEOUT& out_handle_ptr, WAVEHDR& header_ptr){
    //再生を停止する
    waveOutReset(out_handle_ptr);

    //バッファを解除する
    waveOutUnprepareHeader(out_handle_ptr, &header_ptr, sizeof(WAVEHDR));
}

void close_output_device(HWAVEOUT& out_handle_ptr){
    //出力デバイスを閉じる
    waveOutClose(out_handle_ptr);
}