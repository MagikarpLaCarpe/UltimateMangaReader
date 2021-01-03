#ifndef MANGAPLUS_H
#define MANGAPLUS_H

#include "abstractmangasource.h"
#include "mangainfo.h"
#include "thirdparty/picoproto.h"

class MangaPlus : public AbstractMangaSource
{
public:
    explicit MangaPlus(NetworkManager *dm);

    bool updateMangaList(UpdateProgressToken *token) override;
    void updateMangaInfoAsync(QSharedPointer<MangaInfo> info) override;
    Result<QSharedPointer<MangaInfo>, QString> getMangaInfo(const QString &mangaUrl,
                                                            const QString &mangaTitle) override;

    void updateMangaInfoFinishedLoading(QSharedPointer<DownloadStringJob> job,
                                        QSharedPointer<MangaInfo> info) override;
    void updateMangaInfoFinishedLoading(QSharedPointer<DownloadBufferJob> job,
                                        QSharedPointer<MangaInfo> info);
    Result<QStringList, QString> getPageList(const QString &chapterUrl) override;

private:
    QString mangalistUrl;
    QString chapterDetailUrl;
    QString pagesUrl;
};

#endif  // MANGAPLUS_H
