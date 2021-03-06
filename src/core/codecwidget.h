
#ifndef CODECWIDGET_H
#define CODECWIDGET_H

#include <kcoreaddons_export.h>

#include <QWidget>

#include <KGenericFactory>
#include <QDomDocument>

class FilterOptions;
class ConversionOptions;


/**
 * @short The plugin specific widget for detailed options
 * @author Daniel Faust <hessijames@gmail.com>
 * @version 1.0
 */
class KCOREADDONS_EXPORT FilterWidget : public QWidget
{
    Q_OBJECT
public:
    FilterWidget();
    virtual ~FilterWidget();

    virtual FilterOptions *currentFilterOptions() = 0;
    virtual bool setCurrentFilterOptions( const FilterOptions *_options ) = 0; // returns false if options are invalid (eg. different plugin)

signals:
    void optionsChanged();
};


/**
 * @short The plugin specific widget for detailed options
 * @author Daniel Faust <hessijames@gmail.com>
 * @version 1.0
 */
class KCOREADDONS_EXPORT CodecWidget : public QWidget
{
    Q_OBJECT
public:
    CodecWidget();
    virtual ~CodecWidget();

    virtual ConversionOptions *currentConversionOptions() = 0;
    virtual bool setCurrentConversionOptions( const ConversionOptions *_options ) = 0; // returns false if options are invalid (eg. different plugin)
    virtual void setCurrentFormat( const QString& format ) = 0;
    virtual QString currentProfile() = 0;
    virtual bool setCurrentProfile( const QString& profile ) = 0; // returns false if options are invalid (eg. plugin doesn't support hybrid)
    virtual int currentDataRate() = 0;

signals:
    void optionsChanged();
};

#endif // CODECWIDGET_H
