
float cmEncoders(float cm)
{
	float encoders = 0;
	float radius = 3;
	encoders = cm/((radius * radius * PI)/360);
	return encoders;

}
