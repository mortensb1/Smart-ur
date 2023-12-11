void EncoderRead()
{
  encoderCount = encoder.read()/4;

  if (encoderCount > 3)
  {
    encoder.write(0);
    encoderCount = encoder.read()/4;
  }
  if (encoder.read() < 0)
  {
    encoder.write(15);
    encoderCount = encoder.read()/4;
  }
}