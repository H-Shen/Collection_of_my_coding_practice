type Codec struct {
	long2short map[string]int
	short2long []string
	id int
}


func Constructor() Codec {
	return Codec{
		long2short: make(map[string]int),
		id: 0,
	}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	val, ok := this.long2short[longUrl]
	if ok {
		return this.short2long[val]
	}
	this.long2short[longUrl] = this.id
	this.id++
	this.short2long = append(this.short2long, longUrl)
	return strconv.Itoa(this.id-1)
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	val, err := strconv.Atoi(shortUrl)
	if err != nil {
		log.Fatalln(val)
	}
	return this.short2long[val]
}


/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */
