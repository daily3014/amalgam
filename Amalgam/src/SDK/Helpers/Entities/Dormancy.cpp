bool CDormancy::GetDormancy(int iIndex)
{
	return m_mDormancy.contains(iIndex);
}
bool CDormancy::GetDormancyPosition(int iIndex, Vec3& vPosition)
{
	bool has = m_mDormancy.contains(iIndex);
	if (has)
		vPosition = m_mDormancy[iIndex].Location;

	return has;
}