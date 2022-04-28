struct Video {
private:
    int likes;
    int dislikes;
    int views;
    string content;
public:
    // constructors
    Video(int likes, int dislikes, int views, string content) : 
        likes(likes), 
        dislikes(dislikes),
        views(views),
        content(move(content)) {}
    Video() : Video(-1,-1,-1,"") {}
    // getters
    const int& getLikes() const {
        return likes;
    }
    const int& getDislikes() const {
        return dislikes;
    }
    const int& getViews() const {
        return views;
    }
    const string& getContent() const {
        return content;
    }
    // setters
    void setLikes(const int& likes) {
        this->likes = likes;
    }
    void setDislikes(const int& dislikes) {
        this->dislikes = dislikes;
    }
    void setViews(const int& views) {
        this->views = views;
    }
    void setContent(string content) {
        this->content = move(content);
    }
};


class VideoSharingPlatform {
private:
    static const int MAX_VIDEO_ID = 1e5+2;
    set<int> removedVideoId;
    array<Video, MAX_VIDEO_ID> id2video;
    int currentVideoId;
public:
    VideoSharingPlatform() : currentVideoId(0) {}
    
    int upload(string video) {
        int newId;
        if (!removedVideoId.empty()) {
            if (*removedVideoId.begin() > currentVideoId) {
                newId = currentVideoId;
                ++currentVideoId;
            }
            else {
                newId = *removedVideoId.begin();
                removedVideoId.erase(removedVideoId.begin());
            }
        }
        else {
            newId = currentVideoId;
            ++currentVideoId;
        }
        id2video[newId].setLikes(0);
        id2video[newId].setDislikes(0);
        id2video[newId].setViews(0);
        id2video[newId].setContent(video);
        return newId;
    }
    
    void remove(int videoId) {
        if (id2video[videoId].getLikes() != -1) {
            id2video[videoId].setLikes(-1);
            id2video[videoId].setDislikes(-1);
            id2video[videoId].setViews(-1);
            removedVideoId.insert(videoId);
        }
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (id2video[videoId].getLikes() == -1) {
            return "-1";
        }
        id2video[videoId].setViews(id2video[videoId].getViews() + 1);
        if (endMinute >= (int)id2video[videoId].getContent().size()) {
            return id2video[videoId].getContent().substr(startMinute);
        }
        return id2video[videoId].getContent().substr(startMinute, endMinute - startMinute + 1);
    }
    
    void like(int videoId) {
        if (id2video[videoId].getLikes() != -1) {
            id2video[videoId].setLikes(id2video[videoId].getLikes() + 1);
        }
    }
    
    void dislike(int videoId) {
        if (id2video[videoId].getDislikes() != -1) {
            id2video[videoId].setDislikes(id2video[videoId].getDislikes() + 1);
        }
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (id2video[videoId].getLikes() != -1) {
            return vector<int>{id2video[videoId].getLikes(), id2video[videoId].getDislikes()};
        }
        return vector<int>{-1};
    }
    
    int getViews(int videoId) {
        return id2video[videoId].getViews();
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */