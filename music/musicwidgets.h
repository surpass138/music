#ifndef MUSICWIDGETS_H
#define MUSICWIDGETS_H

#include "base/basewidget.h"
#include "bottom/bottomwidgets.h"
#include "top/topwidgets.h"
#include "middle/middlewidgets.h"

#include <QMediaPlayer>

/**
 * The main layout of music widgets.It is made up of 3 positional widgets.
 * This class in charge of the widgets's connecttion(in master control).
 *
 * The layout include top、middle(left、right)、bottom widgets and each has their own
 * layout control and logic processing.
 */
class MusicWidgets:public BaseWidget
{
    Q_OBJECT
public:
    MusicWidgets(QWidget *parent=0);
    ~MusicWidgets();

    // Update ui by search result.
    void updateUiByRes(QFileInfoList);
    // Used to find out all music files in path
    QFileInfoList findMusicFiles(const QString& path);
    void updateVolume(bool volumeAdd);
private:
    QList<QString> m_refreshSuffixList;
    QMediaPlayer *m_player;

    TopWidgets *m_topwid;
    BottomWidgets *m_bottomwid;
    MiddleWidgets *m_middlewid;

    void initData();
    void initLayout();
    void initPlayerAndConnection();
    void readSetting();
    void setOriginState();
    void savaSetting();
    void saveVolume(int volume);
private slots: 
    void slot_volumeChanged(int);
    void slot_nextSong();
    void slot_preSong();
    void slot_fastForward();
    void slot_fastBackward();
    void slot_playOrPause();
    void slot_changePlayMode();
    void slot_refreshMediaResource();
    // MediaPlayer...
    void slot_onMediaStatusChanged(QMediaPlayer::MediaStatus);
    void slot_onErrorOn(QMediaPlayer::Error);
    void slot_onStateChanged(QMediaPlayer::State);
    void slot_onPositonChanged(qint64);
    void slot_onDuratuonChanged(qint64);

    void slot_onTableItemClicked(int,int);
    void slot_deleteTableItem(int);
    void slot_changePlayerProgress(int);
    void slot_exit();
public slots:
    void slot_onMetaDataAvailableChanged(bool);
protected:

};

#endif // MUSICWIDGETS_H
