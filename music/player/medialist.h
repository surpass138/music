#ifndef MEDIALIST_H
#define MEDIALIST_H
#include<QUrl>
#include <QObject>

enum PlayMode{
    PlayInOrder=0,
    PlayRandom=1,
    PlayOneCircle=2
};

/**
 * Used for manager the music list.
 *
 * Each video item saved with url and you can add、remove
 * or get music item.
 */
class MediaList:public QObject
{
    Q_OBJECT
public:
    MediaList(QObject *parent = 0);

    void clearList();
    void setPlayMode(PlayMode);
    int getPlayMode(){return m_playmode;}
    inline void addPlayList(const QString& path){m_list.append(QUrl::fromLocalFile(path));}
    QUrl getUrlAt(int index);
    QUrl getNextSongUrl();
    QUrl getPreSongUrl();
    void removeItem(int index);
    QList<QUrl> getUrlList(){return m_list;}
    void changePlayMode();
    PlayMode getCurrentPlayMode(){return m_playmode;}
private:
    // Current play list.
    QList<QUrl> m_list;
    int m_currentIndex;
    // Current play index.
    PlayMode m_playmode;
};

#endif // MEDIALIST_H