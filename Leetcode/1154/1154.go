func dayOfYear(date string) int {
	var year, month, day int
	_, err := fmt.Sscanf(date, "%d-%d-%d", &year, &month, &day)
	if err != nil {
		os.Exit(1)
	}
	var date1 = time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
	var date2 = time.Date(year, time.January, 1, 0, 0, 0, 0, time.UTC)
	var days = date1.Sub(date2) / (24*time.Hour)
	return int(days)+1
}